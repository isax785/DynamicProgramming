#ifndef CONSTRUCT_ALL_H
#define CONSTRUCT_ALL_H

#include <string>
#include <vector>
#include <map>

using namespace std;
typedef vector<vector<string>> VV;

// =========================== Brute Force ====================================

VV all_construct_bf(string target, vector<string>& word_bank) {
    if (target.size() == 0) return {{}};
    VV result = {};

    for (string word: word_bank) {
        VV target_ways = {}; 
        if (target.find(word) == 0 && target.size() >= word.size()) {
            string suffix = target.substr(word.size());
            VV suffix_ways = all_construct_bf(suffix, word_bank);

            for (int i=0; i<suffix_ways.size(); i++) {
                target_ways.push_back({word});
                for (int j=0; j<suffix_ways[i].size(); j++) {
                    target_ways[i].push_back(suffix_ways[i][j]);
                }
            }
        if (target_ways.size()>0)
            for (vector<string> way : target_ways) result.push_back(way);
        }
    }
    return result;
}

// =========================== Memoization ====================================

VV all_construct_memo(string target, vector<string>& word_bank, map<string, VV>& memo) {
    if (target.size() == 0) return {{}};
    if (memo.find(target) != memo.end()) return memo[target];
    VV result = {};

    for (string word : word_bank) {
        VV target_ways;
        if (target.find(word) == 0 && target.size() >= word.size()) {
            string suffix = target.substr(word.size());
            VV suffix_ways = all_construct_memo(suffix, word_bank, memo);
        
            for (int i=0; i<suffix_ways.size(); i++) {
                target_ways.push_back({word});
                for (int j=0; j<suffix_ways[i].size(); j++) {
                    target_ways[i].push_back(suffix_ways[i][j]);
                }
            }
        }
        if (target_ways.size()>0) {
            for (vector<string> way : target_ways) {
                result.push_back(way);
            }
        }
        memo[target] = result;
    }
    return result;
};

// =========================== Tabulation =====================================

VV all_construct_table(string target, vector<string>& word_bank) {
    VV table[target.size()+1] = {{}};
    table[0] = {{}};

    for (int i=0; i <= target.size(); i++) {
        for (string word : word_bank) {
            if (i + word.size() <= target.size()) {
                if (target.substr(i, word.size()) == word) {
                    VV new_combinations;
                    for (int j=0; j<table[i].size(); j++) {
                        table[i+word.size()].push_back({word});
                        for (int k=0; k<table[i][j].size(); k++) 
                            table[i+word.size()][j].push_back(table[i][j][k]);
                    }
                }
            }
        }
    }
    return table[target.size()];
};

#endif // CONSTRUCT_ALL_H