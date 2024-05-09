// The provided implementation of the traveling salesman algorithm using a brute-force approach has a time complexity of O(n!), where n is the number of points.

// Here's the breakdown:

// Permutations Generation: Generating all possible permutations of the points requires O(n!) time complexity because there are n! permutations for n points.
// Total Distance Calculation: For each permutation, the total distance is calculated, which requires traversing through all points once. This takes O(n) time.
// Finding Shortest Route: After calculating the total distance for each permutation, the shortest route is found by comparing the distances. This takes O(n!) time because there are n! permutations to check.
// Therefore, the overall time complexity of the algorithm is O(n! * n) ≈ O(n!).

// The space complexity mainly comes from storing the permutations and is also O(n!), as it involves storing all possible permutations of the points.

interface Point {
  x: number;
  y: number;
}

function distance(point1: Point, point2: Point): number {
  const dx = point1.x - point2.x;
  const dy = point1.y - point2.y;
  return Math.sqrt(dx * dx + dy * dy);
}

function permute<T>(arr: T[]): T[][] {
  const permutations: T[][] = [];

  function generate(current: T[], remaining: T[]): void {
    if (remaining.length === 0) {
      permutations.push(current);
    } else {
      for (let i = 0; i < remaining.length; i++) {
        const next = current.concat([remaining[i]]);
        const rest = [...remaining.slice(0, i), ...remaining.slice(i + 1)];
        generate(next, rest);
      }
    }
  }

  generate([], arr);
  return permutations;
}

function calculateTotalDistance(route: number[], points: Point[]): number {
  let totalDistance = 0;
  for (let i = 0; i < route.length - 1; i++) {
    totalDistance += distance(points[route[i]], points[route[i + 1]]);
  }
  totalDistance += distance(points[route[route.length - 1]], points[route[0]]);
  return totalDistance;
}

function findShortestRoute(points: Point[]): number[] {
  const numPoints = points.length;
  let shortestDistance = Infinity;
  let shortestRoute: number[] = [];

  const permutations = permute([...Array(numPoints).keys()]);

  for (let i = 0; i < permutations.length; i++) {
    const currentDistance = calculateTotalDistance(permutations[i], points);
    if (currentDistance < shortestDistance) {
      shortestDistance = currentDistance;
      shortestRoute = permutations[i];
    }
  }

  return shortestRoute;
}

function generateRandomPoints(numPoints: number, minX: number, maxX: number, minY: number, maxY: number): Point[] {
  const points: Point[] = [];
  for (let i = 0; i < numPoints; i++) {
    const x = Math.floor(Math.random() * (maxX - minX + 1)) + minX;
    const y = Math.floor(Math.random() * (maxY - minY + 1)) + minY;
    points.push({ x, y });
  }
  return points;
}

const numPoints = 10, minX = 0, maxX = 10, minY = 0, maxY = 10;

const points = generateRandomPoints(numPoints, minX, maxX, minY, maxY);
const shortestRoute = findShortestRoute(points);
console.log("Shortest Route:", shortestRoute);
console.log("Shortest Distance:", calculateTotalDistance(shortestRoute, points));
