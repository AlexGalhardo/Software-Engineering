import { createGunzip } from 'node:zlib';
import axios from 'axios';
import { parser } from 'stream-json/Parser';
import { streamArray } from 'stream-json/streamers/StreamArray';
import { pick } from 'stream-json/filters/Pick';
import { chain } from 'stream-chain';
import { type Readable } from 'node:stream';
import { Prisma, PrismaClient } from '@prisma/client';

const prisma = new PrismaClient()

const downloadUrl = 'https://www.infojobs.com.br/OfertasMulheresPositivas.json.gz'

interface Job {
  title: string;
  date: string;
  referencenumber: string;
  url: string;
  company: string;
  sourcename: string;
  city?: string | null;
  state: string;
  country: string;
  postalcode?: null;
  description?: string | null;
  salary: string;
  education?: string | null;
  jobtype?: string | null;
  category: string;
  experience?: string | null;
}

interface StreamJob {
  key: number
  value: Job
}

async function saveJobsToDatabase(job: StreamJob) {
  try {
    await prisma.job.create({
      data: {
        company_id: '30',
        code: String(job.value.referencenumber),
      }
    })

    console.log(`Inserted ${job.key}.`)
  } catch (err) {
    if (err instanceof Prisma.PrismaClientKnownRequestError) {
      if (err.code === 'P2002') {
        console.log(`Skipped ${job.key}.`)
        return
      }
    }

    console.error(err)
  }
}

function consumeJobsStream(stream: Readable) {
  const unzip = createGunzip()

  const pipeline = chain([
    stream,
    unzip,
    parser(),
    pick({ filter: "source.job" }),
    streamArray(),
  ])

  pipeline
    .on('data', (data: StreamJob) => {
      saveJobsToDatabase(data)
    })
    .on('error', (err: any) => {
      console.error('An error occurred:', err);
    })
    .on('end', () => {
      const memoryUsage = process.memoryUsage();
      const memoryUsageInMB = {
          rss: (memoryUsage.rss / 1024 / 1024).toFixed(2),
          heapTotal: (memoryUsage.heapTotal / 1024 / 1024).toFixed(2),
          heapUsed: (memoryUsage.heapUsed / 1024 / 1024).toFixed(2),
          external: (memoryUsage.external / 1024 / 1024).toFixed(2),
      };

      console.log(memoryUsageInMB);
    });
}

axios.get(downloadUrl, { responseType: 'stream' })
  .then(response => consumeJobsStream(response.data))

