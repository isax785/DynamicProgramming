// brute force implementation

const howSumBF = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderResult = howSumBF(remainder, numbers);
        if (remainderResult !== null) {
            return [...remainderResult, num]; //append num at the end
        }
    }
    return null;
}

console.log("=== Brute Force ===");
console.log(7, howSumBF(7, [2, 3]));
console.log(7, howSumBF(7, [3, 2])); // swaping numbers provides a different solution
console.log(6, howSumBF(6, [2, 3]));
console.log(7, howSumBF(7, [2, 4]));
console.log(7, howSumBF(7, [2, 4]));
console.log(8, howSumBF(8, [2, 3, 5]));
console.log(8, howSumBF(8, [5, 3, 2])); // different order of numbers gives a different solution

// MEMOIZATION

const howSum = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderResult = howSum(remainder, numbers, memo);
        if (remainderResult !== null) {
            memo[targetSum] = [...remainderResult, num]; //append num at the end
            return memo[targetSum];
        }
    }
    memo[targetSum] = null;
    return null;
}

console.log("=== Memoization ===");
console.log(howSum(300, [7, 14]));

// TABULATION

const howSumTab = (targetSum, numbers) => {
    const table = Array(targetSum + 1).fill(null);
    table[0] = []; // seed
    
    for (let i = 0; i <= targetSum; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                table[i + num] = [...table[i], num];
            }
        }
    }

    return table[targetSum];
}

console.log("=== Tabulation ===");
console.log(howSumTab(300, [7, 14]));