const fib = (n) => {
    if (n <= 2) return 1;
    return fibBF(n - 1) + fibBF(n - 2); 
};

// MEMOIZATION
// js object: key = arg to fn, value = return value

const fibMem = (n, memo = {}) => {
    if  (n in memo) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fibMem(n - 1, memo) + fibMem(n - 2, memo);
    return memo[n];
}

// TABULATION

const fibTab = (n) => {
    const table = Array(n + 1).fill(0); //one more position (n+1) to apply the same iterative procedure for sum
    table[1] = 1;
    for (let i = 0; i <= n; i++) {
        table[i+1] += table[i];
        table[i+2] += table[i];
    }
    return table[n];
}

// TESTING

const test = [10, 20];
const testDyn = [...test, 100, 200];

console.log('=== CLASSIC ===')
for (let t of test) console.log(fibBF(t));
console.log('=== MEMOIZATION ===')
for (let t of testDyn) console.log(fibMem(t));
console.log('=== TABULATION ===')
for (let t of testDyn) console.log(fibTab(t));


