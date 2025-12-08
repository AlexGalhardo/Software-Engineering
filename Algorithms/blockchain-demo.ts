import * as crypto from 'crypto';

// Classe que representa um bloco na blockchain
class Block {
  public timestamp: string;
  public previousHash: string;
  public hash: string;
  public data: string;
  public nonce: number;

  constructor(timestamp: string, data: string, previousHash = '') {
    this.timestamp = timestamp;
    this.data = data;
    this.previousHash = previousHash;
    this.nonce = 0;
    this.hash = this.calculateHash();
  }

  // Calcula o hash do bloco baseado nas suas propriedades
  calculateHash(): string {
    return crypto
      .createHash('sha256')
      .update(this.previousHash + this.timestamp + JSON.stringify(this.data) + this.nonce)
      .digest('hex');
  }

  // Prova de trabalho: tenta encontrar um hash que comece com um número suficiente de zeros
  mineBlock(difficulty: number): void {
    while (this.hash.substring(0, difficulty) !== Array(difficulty + 1).join('0')) {
      this.nonce++;
      this.hash = this.calculateHash();
    }

    console.log(`Bloco minerado: ${this.hash}`);
  }
}

// Classe que representa a blockchain
class Blockchain {
  public chain: Block[];
  public difficulty: number;

  constructor() {
    this.chain = [this.createGenesisBlock()];
    this.difficulty = 4;
  }

  // Gera o bloco inicial da cadeia (bloco gênesis)
  createGenesisBlock(): Block {
    return new Block('01/01/2024', 'Genesis Block', '0');
  }

  // Retorna o último bloco da cadeia
  getLatestBlock(): Block {
    return this.chain[this.chain.length - 1];
  }

  // Adiciona um novo bloco à blockchain após minerá-lo
  addBlock(newBlock: Block): void {
    newBlock.previousHash = this.getLatestBlock().hash;
    newBlock.mineBlock(this.difficulty);
    this.chain.push(newBlock);
  }

  // Verifica se a blockchain é válida, iterando sobre todos os blocos
  isChainValid(): boolean {
    for (let i = 1; i < this.chain.length; i++) {
      const currentBlock = this.chain[i];
      const previousBlock = this.chain[i - 1];

      if (currentBlock.hash !== currentBlock.calculateHash()) {
        return false;
      }

      if (currentBlock.previousHash !== previousBlock.hash) {
        return false;
      }
    }

    return true;
  }
}

// Testando a blockchain
const bitcoinBlockchain = new Blockchain();

console.log('Minerando bloco 1...');
bitcoinBlockchain.addBlock(new Block('10/10/2024', 'Transaction data: 100 BTC sent from A to B'));

console.log('Minerando bloco 2...');
bitcoinBlockchain.addBlock(new Block('12/10/2024', 'Transaction data: 50 BTC sent from B to C'));

console.log(JSON.stringify(bitcoinBlockchain, null, 4));

// Verificando se a blockchain é válida
console.log(`A blockchain é válida? ${bitcoinBlockchain.isChainValid()}`);
