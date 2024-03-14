const cluster = require('cluster');
const totalCPUs = require('os').cpus().length;

const secretCodeToFind = 213405;

const minNumber = 100000;
const maxNumber = 999999;
const totalNumbersToEachWorkerToTest = Math.floor((maxNumber - minNumber) / totalCPUs)

const indexes = [0, 1, 2, 3, 4, 5, 6, 7]
const startAt = []; // numbers to each worker start to test
const endAt = []; // numbers to each worker end test

for (let i = 0; i < indexes.length; i++) {
	if (i === 0) {
		startAt[0] = minNumber
		endAt[0] = minNumber + totalNumbersToEachWorkerToTest
	}
	else {
		startAt[i] = endAt[i - 1] + 1
		endAt[i] = startAt[i] + totalNumbersToEachWorkerToTest > maxNumber ? maxNumber : startAt[i] + totalNumbersToEachWorkerToTest
	}
}

function sleep (ms) {
	return new Promise(resolve => setTimeout(resolve, ms));
}

if (cluster.isMaster) {

	for (let i = 0; i < totalCPUs; i++) {

		const worker = cluster.fork();

		worker.on('message', (message) => {

			console.log(`\nWORKER ID ${worker.process.pid} => received message: ${message}\n`);

			if (message === 'SECRET CODE FOUND') {

				console.log(`\nThe Secret Code ${secretCodeToFind} was found! Terminating all workers...\n`);

				for (const id in cluster.workers) {
					cluster.workers[id].kill();
				}
			}
		});
	}

	let workerIndex = 0;

	for (const index of indexes) {
		const worker = Object.values(cluster.workers)[workerIndex];
		if (worker) {
			const object = {
				start: startAt[index],
				end: endAt[index]
			}
			worker.send(object);
			workerIndex = (workerIndex + 1) % totalCPUs;
		}
	}

	cluster.on('exit', (worker, code, signal) => {
		console.log(`Worker ${worker.process.pid} finished his job!`);
	});

} else {
	process.on('message', async ({ start, end }) => {

		for (let i = start; i <= end; i++) {

			console.log(`...WORKER ID ${process.pid} => trying number: ${i}`);

			await sleep(25)

			if (i === secretCodeToFind) {
				console.log(`\n\nTHE SECRET CODE is =========> ${i}\n\n`)
				process.send('SECRET CODE FOUND');
				break
			}
		}
	});
}