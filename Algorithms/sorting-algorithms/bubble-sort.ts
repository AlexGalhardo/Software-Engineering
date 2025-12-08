import generateArrayRandomUniqueIntegersNumbers from './create-unsort-array.js';
import colors from 'ansi-colors';
import cliProgress from 'cli-progress';

const progressBar = new cliProgress.SingleBar({
  format: '{duration} seconds... ' + colors.cyan('{bar}') + ' {percentage}% ==> Total {value}/{total} numbers sorted',
  barCompleteChar: '\u2588',
  barIncompleteChar: '\u2591',
  hideCursor: true
}, cliProgress.Presets.shades_classic);

function bubbleSort(array: number[]) {
  const length: number = array.length;
  let swapped: boolean;

  progressBar.start(length, 0);
  do {
    swapped = false;
    for (let i = 0; i < length - 1; i++) {
      if (array[i] > array[i + 1]) {
        const temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
    progressBar.increment()
  } while (swapped);
  progressBar.stop();

  return array;
}

console.time('Sorting Time');
console.log("Bubble Sort Sorted array: ", bubbleSort(generateArrayRandomUniqueIntegersNumbers(100000)));
console.timeEnd('Sorting Time');