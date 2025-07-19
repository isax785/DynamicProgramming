const gridTravelerBF = (m, n) => {
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    return gridTravelerBF(m - 1, n) + gridTravelerBF(m, n - 1);
}

// MEMOIZATION

const gridTravelerMem = (m, n, memo={}) => {
    const key = m + ',' + n;
    if (key in memo) return memo[key];
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    memo[key] = gridTravelerMem(m - 1, n, memo) + gridTravelerMem(m, n - 1, memo);
    return memo[key];
}

const gridTravelerMemUpgraded = (m, n, memo={}) => {
    const key = m + ',' + n;
    const key_rev = n + ',' + m;
    if (key in memo) return memo[key];
    if (key_rev in memo) return memo[key_rev];
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    memo[key] = gridTravelerMemUpgraded(m - 1, n, memo) + gridTravelerMemUpgraded(m, n - 1, memo);
    return memo[key];
}

// TABULATION

const gridTravelerTab = (m, n) => {
    const table = Array(m + 1)
        .fill()
        .map(() => Array(n + 1).fill(0));
    table[1][1] = 1;
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            const current = table[i][j];
            if (j + 1 <= n) table[i][j + 1] += current;
            if (i + 1 <= m) table[i + 1][j] += current;
        }
    }

    return table[m][n];
}

// TESTING

const test = [[3, 4], [5, 5]];
const testDyn = [...test, [18, 18], [18, 18]];

console.log('=== CLASSIC ===')
for (let t of test) {
    console.log(gridTravelerBF(t[0], t[1]));
}
console.log('=== MEMOIZATION ===')
for (let t of testDyn) console.log(gridTravelerMem(t[0], t[1]));
for (let t of testDyn) console.log(gridTravelerMemUpgraded(t[0], t[1]));
console.log('=== TABULATION ===')
for (let t of testDyn) console.log(gridTravelerTab(t[0], t[1]));