const bestSumBF = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderCombination = bestSumBF(remainder, numbers);
        if (remainderCombination !== null) {
            const combination = [...remainderCombination, num];
            // check for shortest combination and update
            if (shortestCombination === null || combination.length < shortestCombination.length) {
                shortestCombination = combination;
            }
        }
    }
    return shortestCombination;
}

console.log(bestSumBF(7, [5, 3, 4, 7]));

// Memoization

const bestSum = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderCombination = bestSum(remainder, numbers, memo);
        if (remainderCombination !== null) {
            const combination = [...remainderCombination, num];
            // check for shortest combination and update
            if (shortestCombination === null || combination.length < shortestCombination.length) {
                shortestCombination = combination;
            }
        }
    }
    memo[targetSum] = shortestCombination;
    return shortestCombination;
}

console.log(bestSum(300, [4, 3]));
console.log(bestSum(300, [7, 14]));


// Tabulation

const bestSumTab = (targetSum, numbers) => {
    const table = Array(targetSum + 1).fill(null);
    table[0] = [];

    for(let i = 0; i <= targetSum; i++) {
        if (table[i] !== null) {
            for (let num of numbers) {
                const combination = [ ...table[i], num];
                if (!table[i+num] || table[i+num].length > combination.length){
                    //if this current combination is shorter than what is already stored
                    table[i+num] = combination;
                }
            }
        }
    }
    return table[targetSum];
}

console.log(bestSumTab(300, [4, 3]));
console.log(bestSumTab(300, [7, 14]));