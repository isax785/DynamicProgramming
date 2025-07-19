#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// =========================== Brute Force ====================================

bool can_construct_bf(string target, vector<string>& word_bank) {
    if (target == "") return true;

    for (string word : word_bank) {
        if (target.find(word) == 0 && target.size() >= word.size()) {
            // cout << target << " - " << word << endl; // DEBUG
            string suffix = target.substr(word.size());
            if (can_construct_bf(suffix, word_bank) == true) return true;
        }
    }
    return false;
}

// =========================== Memoization ====================================

bool can_construct_memo(string target, vector<string>& word_bank, map<string, bool>& memo) {
    if (target == "") return true;
    if (memo.find(target) != memo.end()) return memo[target];
    
    for (string word : word_bank) {
        if (target.find(word) == 0 && target.size() >= word.size()) {
            // cout << target << " - " << word << endl; // DEBUG
            string suffix = target.substr(word.size());
            memo[target] = can_construct_memo(suffix, word_bank, memo);
            if (memo[target] == true) return true;
        }
    }
    // memo[target] = false; // CHECK: is it needed?
    return false;
}

// =========================== Tabulation =====================================

bool can_construct_table(string target, vector<string>& word_bank) {
    bool table[target.size()+1] = {false}; // initialization of the full array
    table[0] = true;

    for (int i=0; i<=target.size(); i++) {
        if (table[i] == true) {
            for (string word : word_bank) {
                if (i+word.size() <= target.size()) {
                    // cout << i << " " << target.substr(i, word.size()) << " - " << word << endl; // DEBUG
                    if (target.substr(i, word.size()) == word) {
                    cout << "HERE" << endl;
                    table[i+word.size()] = true;
                }
                }
            }
        }
    }
    return table[target.size()];
}

// =============================== Run ========================================

int main() {
    string phrase = "aabbggffff";
    vector<string> word_bank1 = {"a", "g", "f"};
    vector<string> word_bank2 = {"a", "b", "g", "f"};
    cout << "BF: " << can_construct_bf(phrase, word_bank1) << endl;
    cout << "BF: " << can_construct_bf(phrase, word_bank2) << endl;
    map<string, bool> memo1 = {};
    map<string, bool> memo2 = {};
    cout << "MEMO: " << can_construct_memo(phrase, word_bank1, memo1) << endl;
    cout << "MEMO: " << can_construct_memo(phrase, word_bank2, memo2) << endl;
    cout << "TAB: " << can_construct_table(phrase, word_bank1) << endl;
    cout << "TAB: " << can_construct_table(phrase, word_bank2) << endl;
    return 0;
}