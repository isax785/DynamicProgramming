const canSumSlow = (targetSum, numbers) => {
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for (let num of numbers) {
        const remainder = targetSum - num;
        if (canSumSlow(remainder, numbers) === true) {
            return true;
        }
    }
    return false;
}

// now add MEMOIZATION

const canSum = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for (let num of numbers) {
        const remainder = targetSum - num;
        if (canSum(remainder, numbers, memo) === true) {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

// console.log(canSum(7, [2, 3])); //true
// console.log(canSum(7, [5, 3, 4, 7])); //true
// console.log(canSum(7, [2, 4])); //false
// console.log(canSum(8, [2, 3, 5])); //true
// console.log(canSum(300, [7, 14])); //false

// now TABULATION

const canSumTab = (targetSum, numbers) => {
    const table = Array(targetSum + 1).fill(false);
    table[0] = true; // seed value
    for (let i = 0; i < targetSum; i++) {
        if (table[i] === true) {
            for (let num of numbers) {
                table[i+num] = true;  //no if is needed because it extends the array automatically
            }
        }
    }

    return table[targetSum];
}

console.log(canSumTab(8, [2, 3, 5])); //true
console.log(canSumTab(300, [7, 14])); //false