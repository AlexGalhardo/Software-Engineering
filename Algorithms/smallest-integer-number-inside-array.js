function findSmallestIntegerNumberInsideArray(array) {
    const set = new Set(array);
    let smallestPositive = 1;

    while (set.has(smallestPositive)) {
        smallestPositive++;
    }

    return smallestPositive;
}