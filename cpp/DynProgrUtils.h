#ifndef DYNPROGRUTILS_H
#define DYNPROGRUTILS_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <chrono>


namespace du {
    void print_vector(std::vector<int> vec) {
        for (int value : vec) std::cout << value << " ; ";
        std::cout << std::endl;
    }

    std::vector<int> NULL_VECTOR = {NULL};


    void decorator(int n, long int (*func)(int), std::string text) {
        auto start = std::chrono::high_resolution_clock::now();
        int res = func(n);
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

        std::cout << text << "\nResult: " << res << "\nExec Time: " << time.count() << " ms\n\n";
    }

    void decorator(int n, int m, int (*func)(int, int), std::string text) {
        auto start = std::chrono::high_resolution_clock::now();
        int res = func(n, m);
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

        std::cout << text << "\nResult: " << res << "\nExec Time: " << time.count() << " ms\n\n";
    }

    void print_vector_vector(std::vector<std::vector<std::string>> vec) {
        if (vec.size() == 0) {
            std::cout << "[ ]" << std::endl;
        }
        else {
            std::cout << "[ " << std::endl;
            for (auto v : vec) {
                std::cout << "\t[ ";
                for (std::string s : v) std::cout << "'" << s << "', ";
                std::cout << "], " << std::endl;
            }
            std::cout << " ]" << std::endl;
        }
    }
}

#endif // DYNPROGRUTILS_H