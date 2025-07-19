#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// =========================== Brute Force ====================================

int count_construct_bf(string target, vector<string>& word_bank) {
    // cout << target << endl; // DEBUG
    if (target == "") return 1;
    int count = 0;

    for (string word: word_bank) {
        if (target.find(word) == 0 && target.size() >= word.size()) {
            string suffix = target.substr(word.size());
            int subcount = count_construct_bf(suffix, word_bank);
            count += subcount;
        }
    }
    return count;
}

// =========================== Memoization ====================================

int count_construct_memo(string target, vector<string>& word_bank, map<string, bool>& memo) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return 1;
    int count = 0;

    for (string word : word_bank) {
        if (target.find(word) == 0 && target.size() >= word.size()) {
            string suffix = target.substr(word.size());
            int subcount = count_construct_memo(suffix, word_bank, memo);
            count += subcount;
            // cout << word << " " << count << endl;  // DEBUG
        }
    }
    memo[target] = count;
    return count;
}

// =========================== Tabulation =====================================

int count_construct_table(string target, vector<string>& word_bank) {
    int table[target.size()+1] = {0};
    table[0] = 1;
    for (int i=0; i<=target.size(); i++) {
        if (table[i] != 0) {
            for (string word : word_bank) {
                if (target.size() - i >= word.size()) {
                    if (target.substr(i, word.size()) == word) {
                        // cout << " -- " << word << endl; // DEBUG
                        table[i + word.size()] += table[i];
                    }
                }
            }
        }
    }
    // for (int j=0; j<=target.size(); j++) { cout << table[j] << " "; } cout << endl; // DEBUG

    return table[target.size()];
}

// ============================= Run ==========================================

int main() {
    string phrase = "aabbggffff";
    vector<string> word_bank1 = {"a", "g", "f"};
    vector<string> word_bank2 = {"a", "b", "g", "f"};
    cout << "BF: " << count_construct_bf(phrase, word_bank1) << endl;
    cout << "BF: " << count_construct_bf(phrase, word_bank2) << endl;
    map<string, bool> memo1 = {};
    map<string, bool> memo2 = {};
    cout << "MEMO: " << count_construct_memo(phrase, word_bank1, memo1) << endl;
    cout << "MEMO: " << count_construct_memo(phrase, word_bank2, memo2) << endl;
    cout << "TAB: " << count_construct_table(phrase, word_bank1) << endl;
    cout << "TAB: " << count_construct_table(phrase, word_bank2) << endl;
    return 0;
}