import { gunzip } from 'node:zlib';
import axios from 'axios';
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

async function saveJobToDatabase(job: Job) {
  try {
    await prisma.job.create({
      data: {
        company_id: '30',
        code: String(job.referencenumber),
      }
    })
  } catch (err) {
    if (err instanceof Prisma.PrismaClientKnownRequestError) {
      if (err.code === 'P2002') {
        return
      }
    }

    console.error(err)
  }
}

function consumeResponse(response: ArrayBuffer) {
  gunzip(response, async (err, data) => {
    if (err) {
      console.error(err)
      process.exit()
    }

    const jobs = JSON.parse(data.toString()).source.job

    await Promise.all(jobs.map(async (job: Job) => {
      await saveJobToDatabase(job)
    }))

    const memoryUsage = process.memoryUsage();
    const memoryUsageInMB = {
      rss: (memoryUsage.rss / 1024 / 1024).toFixed(2),
      heapTotal: (memoryUsage.heapTotal / 1024 / 1024).toFixed(2),
      heapUsed: (memoryUsage.heapUsed / 1024 / 1024).toFixed(2),
      external: (memoryUsage.external / 1024 / 1024).toFixed(2),
    };

    console.log(memoryUsageInMB);
  })
}

axios.get(downloadUrl, { responseType: 'arraybuffer' })
  .then(response => consumeResponse(response.data))

