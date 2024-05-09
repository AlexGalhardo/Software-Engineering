export default function generateArrayRandomUniqueIntegersNumbers(arraySize: number): number[] {
  let array: number[] = [];
  let set = new Set<number>();

  while (set.size < arraySize) {
    let randomNumber = Math.floor(Math.random() * arraySize) + 1;
    set.add(randomNumber);
  }
  set.forEach(number => array.push(number));
  return array;
}

// let millionUniqueRandomNumbers = generateRandomUniqueArray(1000000);
// console.log(millionUniqueRandomNumbers);
// console.log(millionUniqueRandomNumbers.length);
