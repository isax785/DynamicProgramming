const canConstructBF = (target, wordBank) => {
    if (target === '') return true;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            if (canConstructBF(suffix, wordBank) === true) {
                return true;
            }
        }
    }
    return false;
}

console.log(canConstructBF("abcdef", ["ab", "abc", "cd", "def", "abcd"]));

const canConstructMem = (target, wordBank, memo={}) => {
    if (target in memo) return memo[target];
    if (target === '') return true;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            if (canConstructMem(suffix, wordBank, memo) === true) {
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}

console.log(canConstructMem("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "ef"
]))
console.log(canConstructMem("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
]))


// now TABULATION

const canConstructTab = (target, wordBank) => {
    const table = Array(target.length + 1).fill(false);
    table[0] = true // it means that the empty string can always be generated

    for(let i = 0; i <= target.length; i++) {
        if (table[i] === true) {
            for (let word of wordBank) {
                // if the word matches the characters starting at position i
                if (target.slice(i, i + word.length) === word) {
                    table[i + word.length] = true;
                }
            }
        }
    }

    return table[target.length];
}


console.log(canConstructTab("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(canConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "ef"
]))
console.log(canConstructTab("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
]))