#include <iostream>
#include <map>
#include <chrono>
#include "DynProgrUtils.h"
#include "./functions_h/fibonacci_all.h"

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    int test_std[] = {30, 40};
    int len_std = sizeof(test_std)/sizeof(test_std[0]);
    
    for(int i=0; i < len_std; i++)
    {
        int n = test_std[i];
        du::decorator(n, fib, "BF: " + to_string(n));
        du::decorator(n, fib_memo_wrapper, "MEM: " + to_string(n));
        du::decorator(n, fib_table, "TAB: " + to_string(n));
    }

    cout << "======= ADVANCED =======" << endl;
    // for MEMO and TAB only
    int test_adv[] = {int(1e4), int(5e4), int(1e5), int(5e5)};
    int len_adv = sizeof(test_adv)/sizeof(test_adv[0]);

    for(int i=0; i < len_adv; i++)
    {
        int n = test_adv[i];
        map<int,int> m;
        cout << "Calculating " << n << endl;
        try {
            du::decorator(n, fib_memo_wrapper, "MEM: " + to_string(n));
            du::decorator(n, fib_table, "TAB: " + to_string(n));
            du::decorator(n, fib_table_r1, "TAB r1: " + to_string(n));
        }
        catch(...) {
            cout << "Failed with n = " << n << endl;
        }
    }
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);

    cout << "Total time: " << time.count() << "ms" << endl;

    return 0;
}