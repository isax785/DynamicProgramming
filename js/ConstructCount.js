const countConstructBF = (target, wordBank) => {
    if (target === '') return 1;

    let totalCount = 0; // initialized at each recursion otherwise there will be an overestimation of total count

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const numWaysForRest = countConstructBF(target.slice(word.length), wordBank);
            totalCount += numWaysForRest;
        }
    }
    return totalCount;
}

console.log(countConstructBF("ab", ['a', 'b', 'ab']));
console.log(countConstructBF("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(countConstructBF("purple", ["purp", "p", "ur", "le", "purpl"]));

const countConstructMem = (target, wordBank, memo={}) => {
    if (target in memo) return memo[target];
    if (target === '') return 1;

    let totalCount = 0; // initialized at each recursion otherwise there will be an overestimation of total count

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const numWaysForRest = countConstructMem(target.slice(word.length), wordBank, memo);
            totalCount += numWaysForRest;
        }
    }
    memo[target] = totalCount;
    return totalCount;
}

console.log(countConstructMem("ab", ['a', 'b', 'ab']));
console.log(countConstructMem("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(countConstructMem("purple", ["purp", "p", "ur", "le", "purpl"]));
console.log(countConstructMem("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "ef"
]))
console.log(countConstructMem("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
]))

// now TABULATION

const countConstructTab = (target, wordBank) => {
    const table = Array(target.length + 1).fill(0);
    table[0] = 1;

    for (let i = 0; i <= target.length; i++) {
        for (let word of wordBank) {
            if (target.slice(i, i + word.length) === word){
                table[i + word.length] += table[i];
            }
        }
    }

    return table[target.length];
} 

console.log('=== TABULATION ===');
console.log(countConstructTab("ab", ['a', 'b', 'ab']));
console.log(countConstructTab("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(countConstructTab("purple", ["purp", "p", "ur", "le", "purpl"]));
console.log(countConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "ef"
]))
console.log(countConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
]))