function hanoiTower(n: number, source: string, auxiliary: string, destination: string): void {
  if (n === 1) {
    console.log(`Move disk 1 from ${source} to ${destination}`);
    return;
  }
  hanoiTower(n - 1, source, destination, auxiliary);
  console.log(`Move disk ${n} from ${source} to ${destination}`);
  hanoiTower(n - 1, auxiliary, source, destination);
}

hanoiTower(5, 'A', 'B', 'C');
