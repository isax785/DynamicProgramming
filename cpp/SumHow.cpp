#include <iostream>
#include <vector>
#include <map>
#include "DynProgrUtils.h"

using namespace std;

void print_vector(vector<int> vec) {
    for (int value : vec) cout << value << " ; ";
    cout << endl;
}

vector<int> NULL_VECTOR = {NULL};
map<int, vector<int>> EMPTY_MAP = {};

// =========================== Brute Force ====================================

vector<int> how_sum_bf(int target_sum, vector<int>& numbers) {
    if (target_sum == 0) return {};
    if (target_sum < 0) return NULL_VECTOR;

    for (int num : numbers) {
        int remainder = target_sum - num;
        vector<int> remainder_results = how_sum_bf(remainder, numbers);
        if (remainder_results != NULL_VECTOR) {
            remainder_results.push_back(num);
            return remainder_results;
            }
    }
    return NULL_VECTOR;
}

// =========================== Memoization ====================================

vector<int> how_sum_memo(int target_sum, vector<int>& numbers, map<int, vector<int>>& memo) {
    if (memo.find(target_sum) != memo.end()) return memo[target_sum];
    if (target_sum == 0) return {};
    if (target_sum < 0) return NULL_VECTOR;

    for (int num : numbers) {
        int remainder = target_sum - num;
        vector<int> remainder_results = how_sum_memo(remainder, numbers, memo);
        if (remainder_results != NULL_VECTOR) {
            remainder_results.push_back(num);
            memo[remainder] = remainder_results;
            return remainder_results;
        }
    }
    memo[target_sum] = NULL_VECTOR;
    return NULL_VECTOR;
}

// =========================== Tabulation =====================================

vector<int> how_sum_table(int target_sum, vector<int>& numbers) {
    vector<int> table[target_sum+1];
    for (int i=0; i < target_sum+1; i++) table[i] = {NULL}; 
    cout << "Table size: " << sizeof(table)/sizeof(table[0]) << endl;
    table[0] = {};

    for (int i=0; i<=target_sum; i++) {
        if (table[i] != NULL_VECTOR) {
            for (int n=0; n<numbers.size(); n++) {
                int num = numbers[n];
                // NOTE: add conditional to avoid segmentation fault error
                if (i + num < target_sum+1) {
                    vector<int> tmp = table[i];
                    tmp.push_back(num);
                    // cout << "{ DBG: " << num << " " << i << " }" << endl; 
                    table[i+num] = tmp;
                }
            }
        }
    }

    // cout << "HERE! " << endl; // DEBUG
    return table[target_sum];
}

// ============================= Run ==========================================

int main() {
    vector<int> target_sums = {12, 13};
    vector<vector<int>> numbers = {{2, 4, 5}, {1, 2}};
    vector<map<int, vector<int>>> memos;
    for (int i=0; i<target_sums.size(); i++) memos.push_back({});

    for (int i=0; i<target_sums.size(); i++) {
        int target_sum = target_sums[i];
        vector<int> nums = numbers[i];
        map<int, vector<int>> memo = memos[i];

        cout << "Target: " << target_sum << endl << "Numbers: ";
        print_vector(nums);
        cout << "=== BruteForce === " << endl;
        print_vector(how_sum_bf(target_sum, nums));
        cout << "=== Memo === " << endl;
        print_vector(how_sum_memo(target_sum, nums, memo));
        cout << "=== Table === " << endl;
        print_vector(how_sum_table(target_sum, nums));
    }
}