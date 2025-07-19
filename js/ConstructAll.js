const allConstructBF = (target, wordBank) => {
    if (target == '') return [[]]; // a 2D empty array is retuned

    const result = []

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            const suffixWays = allConstructBF(suffix, wordBank); // 1D array
            const targetWays = suffixWays.map(way => [word, ...way]) // 2D array
            result.push(...targetWays);
        }
    }
    return result;
}

console.log(allConstructBF("ab", ['a', 'b', 'ab']));
console.log(allConstructBF("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(allConstructBF("purple", ["purp", "p", "ur", "le", "purpl"]));


const allConstructMem = (target, wordBank, memo={}) => {
    if (target == '') return [[]]; // a 2D empty array is retuned

    const result = []

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            const suffixWays = allConstructMem(suffix, wordBank, memo); // 1D array
            const targetWays = suffixWays.map(way => [word, ...way]) // 2D array
            result.push(...targetWays);
        }
    }
    memo[target] = result;
    return result;
}

console.log(allConstructMem("ab", ['a', 'b', 'ab']));
console.log(allConstructMem("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(allConstructMem("purple", ["purp", "p", "ur", "le", "purpl"]));

// now TABULATION

const allConstructTab = (target, wordBank) => {
    const table = Array(target.length + 1)
        .fill()
        .map(() => []);
    table[0] = [[]];

    for (let i = 0; i < target.length; i++) {
        for (let word of wordBank) {
            if (target.slice(i, i + word.length) === word) {
                const newCombinations = table[i].map(subarray => [...subarray, word]);
                table[i + word.length].push(...newCombinations);
            }
        }
    }

    return table[target.length];
}


console.log('=== TABULATION ===')
console.log(allConstructTab("ab", ['a', 'b', 'ab']));
console.log(allConstructTab("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(allConstructTab("purple", ["purp", "p", "ur", "le", "purpl"]));