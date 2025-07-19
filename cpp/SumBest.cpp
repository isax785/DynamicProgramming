#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_vector(vector<int> vec) {
    for (int value : vec) cout << value << " ; ";
    cout << endl;
}
vector<int> const NULL_VECTOR = {NULL};
map<int, vector<int>> EMPTY_MAP = {};

// =========================== Brute Force ====================================

vector<int> best_sum_bf(int target_sum, vector<int>& numbers) {
    vector<int> shortest_combination = NULL_VECTOR;
    if (target_sum == 0) return {};
    if (target_sum < 0) return NULL_VECTOR;

    for (int num : numbers) {
        int remainder = target_sum - num;
        vector<int> remainder_combination = best_sum_bf(remainder, numbers);
        if (remainder_combination != NULL_VECTOR) {
            remainder_combination.push_back(num);
            if (shortest_combination == NULL_VECTOR || 
                remainder_combination.size() < shortest_combination.size()) 
                    shortest_combination = remainder_combination;
        }
    }
    return shortest_combination;
}

// =========================== Memoization ====================================

vector<int> best_sum_memo(int target_sum, vector<int>& numbers, 
                          map<int, vector<int>>& memo) {
    vector<int> shortest_combination = NULL_VECTOR;
    
    if (memo.find(target_sum) != memo.end()) return memo[target_sum];
    if (target_sum == 0) return {};
    if (target_sum < 0) return NULL_VECTOR;

    for (int num : numbers) {
        int remainder = target_sum - num;
        vector<int> remainder_combination = 
                        best_sum_memo(remainder, numbers, memo);
        if (remainder_combination != NULL_VECTOR) {
            remainder_combination.push_back(num);
            if (shortest_combination == NULL_VECTOR || 
                remainder_combination.size() < shortest_combination.size()) {
                shortest_combination = remainder_combination;
            }
        }
    }
    memo[target_sum] = shortest_combination;
    return shortest_combination;
}

// =========================== Tabulation =====================================

vector<int> best_sum_tab(int target_sum, vector<int>& numbers) {
    vector<int> table[target_sum+1];

    for (int i=0; i<=target_sum; ++i) table[i] = {NULL_VECTOR};

    table[0] = {};

    for (int i=0; i <= target_sum; ++i) {
        if (table[i] != NULL_VECTOR) {

            for (int j=0; j<numbers.size(); j++) {
                int num = numbers[j];
                // NOTE: add conditional to avoid segmentation fault error
                if (i + num < target_sum+1) {
                    vector<int> combination = table[i];
                    combination.push_back(num);
                    if (table[i+num] == NULL_VECTOR || 
                        table[i+num].size() > combination.size()) {
                        table[i+num] = combination;
                    }
                }
            }
        }
    }   
    return table[target_sum];
}

// ============================= Run ==========================================

int main() {
    vector<int> num1 = {1, 2};
    vector<int> num2 = {5, 3, 4, 7};
    // Brute Force
    cout << "=== Brute Force ===" << endl;
    print_vector(best_sum_bf(0, num1));
    print_vector(best_sum_bf(-12, num1));
    print_vector(best_sum_bf(7, num2));
    print_vector(best_sum_bf(12, num2));
    // Memoization
    cout << "=== Memoization ===" << endl;
    map<int, vector<int>> memo1 = {};
    print_vector(best_sum_memo(100, num1, memo1));
    map<int, vector<int>> memo2 = {};
    print_vector(best_sum_memo(100, num2, memo2));
    // Tabulation
    cout << "=== Tabulation ===" << endl;
    print_vector(best_sum_tab(12, num2));
    print_vector(best_sum_tab(100, num1));
    return 0;
}


/* 
=============================== NOTE =========================================

The following code prints also the NULL (as 0)

    vector<int> test = {NULL, 1, 2, 3};
    cout << test.size() << endl;
    print_vector(test);

Output:

    0 ; 1 ; 2 ; 3 ;

-------------------------------------------------------------------------------

Whenever there is a NULL, it is printed as 0.
When there is no NULL|0 it means that the combination that returns the sum
has been found, as stated by:
    if (target_sum == 0) return {};

-------------------------------------------------------------------------------

A segmentation-fault could occur in tabulation without displaying. The error
is due to the attempt of accesing to a position of `table` that is out
of its length (prevented by the conditional line 74).

both gcc and clang support AddressSanitizer 
(https://en.wikipedia.org/wiki/AddressSanitizer). 
On those two compilers, all you have to do is compile with the 
`-fsanitize=address` command-line option.

*/