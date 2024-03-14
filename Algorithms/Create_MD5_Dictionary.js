const cluster = require('cluster');
const totalCPUs = require('os').cpus().length;
const fs = require('fs')
const crypto = require('crypto')

const dictionaryMD5Passwords = {
	6: [],
	7: [],
	8: [],
	9: [],
	10: [],
	11: [],
	12: [],
	13: []
}

const indexes = [0, 1, 2, 3, 4, 5, 6, 7] // each worker index
const lowerCaseChars = 'abcdefghijklmnopqrstuvwxyzç';
const upperCaseChars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZÇ';
const specialChars = '!@#$%^&*()-_+=<>?/,.:;{}[]|';
const numericChars = '0123456789';

const allPasswordPossibleCharacters = lowerCaseChars + upperCaseChars + specialChars + numericChars;

function generateCombinationsWithRepetition (inputString, combinationLength) {

	function generateHelper (currentPassword) {

		if (currentPassword.length === combinationLength) {
			const password = {
				plainText: currentPassword,
				md5: crypto.createHash('md5').update(currentPassword).digest("hex")
			}

			console.log(password);

			dictionaryMD5Passwords[combinationLength].push(password)

			fs.writeFileSync(`./md5_hash_dictionary/passwords_length_${combinationLength}.json`, JSON.stringify(dictionaryMD5Passwords[combinationLength], null, 4), 'utf8');

			return;
		}

		for (let i = 0; i < inputString.length; i++) {
			const char = inputString[i];
			const newCombination = currentPassword + char;
			generateHelper(newCombination);
		}
	}

	generateHelper('');
}

if (cluster.isMaster) {
	for (let i = 0; i < totalCPUs; i++) {
		const worker = cluster.fork();
		worker.on('message', (message) => {
			console.log(`\nWORKER ID ${worker.process.pid} => received message: ${message}\n`);
		});
	}

	let workerIndex = 0;

	for (const index of indexes) {
		const worker = Object.values(cluster.workers)[workerIndex];
		if (worker) {
			let combinationLength = index + 6
			worker.send(combinationLength);
			workerIndex = (workerIndex + 1) % totalCPUs;
		}
	}

	cluster.on('exit', (worker) => {
		console.log(`Worker ${worker.process.pid} finished his job!`);
	});
} else {
	process.on('message', async (combinationLength) => {
		generateCombinationsWithRepetition(allPasswordPossibleCharacters, combinationLength);
	});
}