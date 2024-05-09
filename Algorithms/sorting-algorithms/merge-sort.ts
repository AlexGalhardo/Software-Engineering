import generateArrayRandomUniqueIntegersNumbers from './create-unsort-array.js';
import colors from 'ansi-colors';
import cliProgress from 'cli-progress';

const progressBar = new cliProgress.SingleBar({
  format: '{duration} seconds... ' + colors.cyan('{bar}') + ' {percentage}% ==> Total {value}/{total} numbers sorted',
  barCompleteChar: '\u2588',
  barIncompleteChar: '\u2591',
  hideCursor: true
}, cliProgress.Presets.shades_classic);

function mergeSort(array: number[]): number[] {
  if (array.length <= 1) {
    return array;
  }

  const mid = Math.floor(array.length / 2);
  const left = mergeSort(array.slice(0, mid));
  const right = mergeSort(array.slice(mid));

  const merge = (left: number[], right: number[]): number[] => {
    let result: number[] = [];
    let i = 0;
    let j = 0;

    while (i < left.length && j < right.length) {
      if (left[i] < right[j]) {
        result.push(left[i]);
        i++;
      } else {
        result.push(right[j]);
        j++;
      }

      progressBar.increment(left.length + right.length); // Increment progress by the length of left and right arrays
    }

    return result.concat(left.slice(i)).concat(right.slice(j));
  };

  return merge(left, right);
}

console.time('Sorting Time');
progressBar.start(1000000, 0); // Start the progress bar before sorting
const sortedArray = mergeSort(generateArrayRandomUniqueIntegersNumbers(1000000));
progressBar.stop(); // Stop the progress bar after sorting is complete
console.log("MergeSort done: ", sortedArray);
console.timeEnd('Sorting Time');
console.log(progressBar.lastDrawnString)
