#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "DynProgrUtils.h"
#include "functions_h/construct_all.h"

using namespace std;
using namespace du;
typedef vector<vector<string>> VV;

int main() {
    string phrase = "abcd";
    vector<string> word_bank1 = {"a", "b", "c"};
    vector<string> word_bank2 = {"a", "b", "c", "d"};
    vector<string> word_bank3 = {"a", "b", "c", "d", "ab"};
    vector<string> word_bank4 = {"a", "b", "g", "f", "gf"};
    vector<string> word_bank5 = {"a", "b", "c", "d", "ab", "abc", "cd"};

    cout << "BF: " << endl;
    print_vector_vector(all_construct_bf(phrase, word_bank1));
    print_vector_vector(all_construct_bf(phrase, word_bank2));
    print_vector_vector(all_construct_bf(phrase, word_bank3));
    // print_vector_vector(all_construct_bf(phrase, word_bank4)); // FIXME:
    print_vector_vector(all_construct_bf(phrase, word_bank5));
    cout << "MEMO: " << endl;
    map<string, VV> memo1 = {};
    map<string, VV> memo2 = {};
    map<string, VV> memo3 = {};
    print_vector_vector(all_construct_memo(phrase, word_bank1, memo1));
    print_vector_vector(all_construct_memo(phrase, word_bank2, memo1));
    print_vector_vector(all_construct_memo(phrase, word_bank3, memo1)); // FIXME:
    print_vector_vector(all_construct_memo(phrase, word_bank4, memo1)); // FIXME:
    cout << "TAB: " << endl;
    print_vector_vector(all_construct_table(phrase, word_bank1));
    print_vector_vector(all_construct_table(phrase, word_bank2));
    // cout << "MEMO: " << all_construct_memo(phrase, word_bank2, memo2) << endl;
    // cout << "TAB: " << all_construct_table(phrase, word_bank1) << endl;
    // cout << "TAB: " << all_construct_table(phrase, word_bank2) << endl;
    string phrase2 = "aabbggff";
    return 0;
}