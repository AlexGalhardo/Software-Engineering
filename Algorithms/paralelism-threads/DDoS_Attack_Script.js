import cluster from 'cluster'
import * as os from 'os'
let numWorkers = os.cpus().length;
import fs from 'fs'
import fetch from 'node-fetch'

const listEndpointsToAttack = [
	// https://jsonplaceholder.typicode.com/users
	'https://jsonplaceholder.typicode.com/users/1',
	'https://jsonplaceholder.typicode.com/users/2',
	'https://jsonplaceholder.typicode.com/users/3',

	// https://jsonplaceholder.typicode.com/posts
	'https://jsonplaceholder.typicode.com/posts/1',
	'https://jsonplaceholder.typicode.com/posts/2',
	'https://jsonplaceholder.typicode.com/posts/3',

	// https://jsonplaceholder.typicode.com/comments
	'https://jsonplaceholder.typicode.com/comments/1',
	'https://jsonplaceholder.typicode.com/comments/2',
	'https://jsonplaceholder.typicode.com/comments/3',

	// https://jsonplaceholder.typicode.com/todos
	'https://jsonplaceholder.typicode.com/todos/1',
	'https://jsonplaceholder.typicode.com/todos/2',
	'https://jsonplaceholder.typicode.com/todos/3'
]

if (cluster.isPrimary) {
	console.log('Master cluster setting up ' + numWorkers + ' workers...');

	for (var i = 0; i < numWorkers; i++) {
		cluster.fork();
	}

	cluster.on('online', function (worker) {
		console.log('Worker ' + worker.process.pid + ' is online');
	});

	cluster.on('exit', function (worker, code, signal) {
		console.log('Worker ' + worker.process.pid + ' died with code: ' + code + ', and signal: ' + signal);
		console.log('Starting a new worker');
		cluster.fork();
	});
} else {

	let timetaken = `Tempo execução no Worker ID:  ${process.pid}`;

	let begin = Date.now();

	console.time(timetaken);

	let totalRequestsMade = 0

	const workerJobStatistics = {
		worker_id: null,
		worker_execution_time: null,
		total_requests_made: 0,
		total_requests_timeout: 0,
		total_requests_http_status_code_200: 0,
		total_requests_fail: 0,
		responses: []
	}

	for (let i = 1; i <= 20; i++) {

		workerJobStatistics.worker_id = process.pid

		for (let i = 0; i < listEndpointsToAttack.length; i++) {

			const request = {
				endpoint: null,
				http_status_code_response: null,
				response: null
			}

			totalRequestsMade += 1

			workerJobStatistics.total_requests_made += 1

			console.log('Worker ID: ' + process.pid + ` => Processing REQUEST GET: ${listEndpointsToAttack[i]} => ` + i)

			try {
				fetch(`${listEndpointsToAttack[i]}`)
					.then((response) => {
						if (response.status === 200) {
							workerJobStatistics.total_requests_http_status_code_200 += 1
							request.http_status_code_response = response.status
							request.endpoint = response.url
						}
						return response
					})
					.then(response => response.json())
					.then(response => {
						if (response) {
							request.response_success = response.success
							request.response = response
						}
						return response
					})
					.then(response => {
						console.log(response)
						workerJobStatistics.responses.push(request)
						try {
							fs.writeFileSync(`./responses/responses-from-worker-id-${process.pid}.json`, JSON.stringify(workerJobStatistics), 'utf8');
						} catch (error) {
							console.log('An error has occurred ', error);
						}
					})
					.catch(err => {
						workerJobStatistics.total_requests_fail += 1
						console.error(err)

						try {
							fs.writeFileSync(`./responses/responses-from-worker-id-${process.pid}.json`, JSON.stringify(workerJobStatistics), 'utf8');
						} catch (error) {
							console.error(err)
						}
					})
			} catch (err) {
				workerJobStatistics.total_requests_timeout += 1
				fs.writeFileSync(`./responses/responses-from-worker-id-${process.pid}.json`, JSON.stringify(workerJobStatistics), 'utf8');
			}
		}
	}

	console.timeEnd(timetaken);

	let end = Date.now();

	let timeSpent = (end - begin) / 1000 + " seconds";

	console.log(`-------> O Worker ID: ${process.pid} processou no total: ${totalRequestsMade} requisições `)

	setTimeout(function () {
		try {
			const jsonData = JSON.parse(fs.readFileSync(`./responses/responses-from-worker-id-${process.pid}.json`, 'utf-8'));
			jsonData.worker_execution_time = timeSpent
			console.log(`--> Tempo execução no Worker ID:  ${process.pid} => `, timeSpent)
			fs.writeFileSync(`./responses/responses-from-worker-id-${process.pid}.json`, JSON.stringify(jsonData, null, 4), 'utf8');
		} catch (error) {
			console.log('An error has occurred ', error);
		}
	}, 7500);
}