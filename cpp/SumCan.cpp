#include <iostream>
#include <vector>
#include <map>

using namespace std;

// =========================== Brute Force ====================================

bool can_sum_bf(int target_sum, vector<int>& numbers) {
    if (target_sum == 0) return true;
    if (target_sum < 0) return false;

    for (int num : numbers) {
        int remainder = target_sum - num;
        if (can_sum_bf(remainder, numbers)) return true;
    }
    return false;
}

// =========================== Memoization ====================================

bool can_sum_memo(int target_sum, vector<int>& numbers, map<int, bool>& memo) {
    if (memo.find(target_sum) != memo.end()) return memo[target_sum];
    if (target_sum == 0) return true;
    if (target_sum < 0) return false;

    for (int num : numbers) {
        int remainder = target_sum - num;
        memo[target_sum] = can_sum_memo(remainder, numbers, memo);
        if (memo[target_sum]) {
            return true;
            }
    }
    return false;
}

// =========================== Tabulation =====================================

bool can_sum_table(int target_sum, vector<int>& numbers) {
    bool table[target_sum + 1] = {false};
    table[0] = true;
    for (int i=0; i < target_sum; i++) {
        if (table[i]) {
            for (int num : numbers) {
                if (i + num <= target_sum) {
                    // stay within the array
                    table[i+num] = true;
                }
            }
        }   
    }
    return table[target_sum];
}

// ============================= Run ==========================================

int main() {
    int n1 = 12;
    int n1_1 = 2e5;
    vector<int> num1 = {1, 2, 4, 6, 7};
    int n2 = 133;
    vector<int> num2 = {2, 4, 6};
    cout << n1 << " - " << can_sum_bf(n1, num1) << endl;
    // cout << n1_1 << " - " << can_sum_bf(n1_1, num1) << endl; // CRASHES!
    map<int, bool> memo1 = {};
    cout << n1 << " - " << can_sum_memo(n1, num1, memo1) << endl;
    // cout << n1_1 << " - " << can_sum_memo(n1_1, num1, memo1) << endl; // CRASHES!
    // cout << n1 << " - " << can_sum_table(n1, num1) << endl;
    // cout << n1_1 << " - " << can_sum_table(n1_1, num1) << endl; // WORKS!
    cout << n2 << " - " << can_sum_table(n2, num2) << endl; // WORKS!
}