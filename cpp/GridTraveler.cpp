#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include "DynProgrUtils.h"

using namespace std;
using namespace std::chrono;

int GridTraveler(int m, int n) {
    printf("n %d m %d", n, m); // DEBUG
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    return GridTraveler(m-1, n) + GridTraveler(m, n-1);
}

int GridTravelerMemo(int m, int n, map<string, int> &memo) {
    // memoizing map key: string
    string key = to_string(m) + "," + to_string(n);
    string key_rev = to_string(n) + "," + to_string(m);

    auto search = memo.find(key);
    if(search != memo.end()) return memo[key];
    auto search_rev = memo.find(key_rev);
    if(search_rev != memo.end()) return memo[key_rev];

    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    memo[key] = GridTravelerMemo(m-1, n, memo) + GridTravelerMemo(m, n-1, memo);

    return memo[key];
}

unsigned long long GridTravelerTab(int m, int n){
    vector<vector<unsigned long long> > table(m, vector<unsigned long long> (n, 0));
    table[1][1] = 1;
    int current;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            current = table[i][j];
            if (j + 1 <= n) table[i][j+1] += current;
            if (i + 1 <= m) table[i+1][j] += current;
            // cout << i << " - " << j << " : " << table[i][j] << endl;
        }
    }
    // cout << "finish" << endl;
    return table[m][n];
}

unsigned long long GridTravelerGPT(int rows, int cols) {
    std::vector<std::vector<unsigned long long>> table(rows + 1, std::vector<unsigned long long>(cols + 1, 0));

    // Base case: there is one way to travel to the starting point
    table[1][1] = 1;

    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j <= cols; ++j) {
            // Move right
            if (j + 1 <= cols) {
                table[i][j + 1] += table[i][j];
            }
            // Move down
            if (i + 1 <= rows) {
                table[i + 1][j] += table[i][j];
            }
        }
    }

    return table[rows][cols];
}


int main() {
    const int NL = 2; // cases light
    int cases_light[NL][2] = {{2, 2},
                              {4, 4}
                              };
    int cl;
    map<string, int> memo;
    for (int i=0; i<NL; i++) {
        cl = *cases_light[i];
        cout << cl << endl;
    }
    int ch[2];
    vector<int[2]> cases_heavy = {{10,10}};

    // cout << GridTravelerMemo(5, 6, memo) << endl;
    // for (auto it = memo.begin(); it != memo.end(); ++it) {
    // std::cout << it->first << " - " << it->second << '\n';
    // }
    cout << GridTravelerGPT(2, 2) << endl;
    // cout << GridTravelerTab(2, 2) << endl; //FIXME: it does not work ?!?!?
}