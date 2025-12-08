import generateArrayRandomUniqueIntegersNumbers from './create-unsort-array.js';
import colors from 'ansi-colors';
import cliProgress from 'cli-progress';

const progressBar = new cliProgress.SingleBar({
  format: '{duration} seconds... ' + colors.cyan('{bar}') + ' {percentage}% ==> Total {value}/{total} numbers sorted',
  barCompleteChar: '\u2588',
  barIncompleteChar: '\u2591',
  hideCursor: true
}, cliProgress.Presets.shades_classic);

function quickSort(array: number[], progress: any): number[] {
  if (array.length <= 1) {
    return array;
  }

  const pivot = array[array.length - 1];
  const left: number[] = [];
  const right: number[] = [];

  for (let i = 0; i < array.length - 1; i++) {
    progress.increment();
    if (array[i] < pivot) {
      left.push(array[i]);
    } else {
      right.push(array[i]);
    }
  }

  progress.stop();
  return [...quickSort(left, progress), pivot, ...quickSort(right, progress)];
}

console.time('Sorting Time');
progressBar.start(1000000, 0);
console.log("QuickSort done: ", quickSort(generateArrayRandomUniqueIntegersNumbers(1000000), progressBar));
console.timeEnd('Sorting Time');
console.log(progressBar.lastDrawnString)
