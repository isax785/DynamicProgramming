#ifndef FIBONACCI_ALL_H
#define FIBONACCI_ALL_H

#include <iostream>
#include <map>

using namespace std;

// Fibonacci sequence:
// 0 - 0
// 1 - 0 1
// 2 - 0 1 1
// 3 - 0 1 1 2
// 4 - 0 1 1 2 3
// 5 - 0 1 1 2 3 5
// 6 - 0 1 1 2 3 5 8
// 7 - 0 1 1 2 3 5 8 13
// 8 - ...

long int fib(int n) {
    // Fibonacci calcualtion with recursion
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

long int fib_memo(int n, map<int, int> & memo) {
    // Fibonacci with recursion and memoization
    if(memo[n]) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);

    return memo[n];
}

long int fib_memo_wrapper(int n) {
    // Avoids the need for initializing the memo map when calling the function
    map<int, int> memo;
    int out = fib_memo(n, memo);
    return out;
}

long int fib_table(int n) {
    // Fibonacci with tabualtion
    int table[n+1];
    fill_n(table, n+1, 0);

    table[1] = 1;
    for (int i=0; i < n; i++)
    {
        table[i+1] += table[i];
        table[i+2] += table[i];
    }
    return table[n];
}

long int fib_table_r1(int n) {
    // Fibonacci with tabualtion - rev1
    // different way to fill the table, starts from cell #2
    long int table[n+1];
    fill_n(table, n, 0);
    table[1] = 1;
    for (int i = 2; i <= n; i++) {
        table[i] = table[i-1] + table[i-2];
    }

    // cout << ">> { dbg: N+1: " << table[n+1] << " }" << endl; // DEBUG
    return table[n];
}

#endif // FIBONACCI_ALL_H