# Coding

## Timing Decorator

Timing decorator for functions:

```cpp
#include <chrono>

void decorator(int n, int (*func)(int), string text) {
    auto start = high_resolution_clock::now();
    int res = func(n);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end-start);

    cout << text << "\nResult: " << res << "\nExec Time: " << time.count() << " ms\n\n";
}
```

## Return `vector<something>`

When a vector is declared as a return, it is not possible to return `NULL`.

Here below two viable solutions for the return:

- `{}` - empty vector
- `{NULL}` - vector with a single `NLULL` element

Otherwise, working with **pointers**, a `nullptr` can be returned.

## `NULL`

The following code prints also the NULL (as 0)

```cpp
    vector<int> test = {NULL, 1, 2, 3};
    cout << test.size() << endl;
    print_vector(test);
```
Output:
```
    0 ; 1 ; 2 ; 3 ;
```
---

Whenever there is a NULL, it is printed as 0.

When there is no NULL|0 it means that the combination that returns the sum has been found, as stated by:

```cpp
    if (target_sum == 0) return {};
```

## Segmentation Fault

A segmentation-fault could occur in tabulation without displaying. The error
is due to the attempt of accesing to a position of `table` that is out
of its length (prevented by the conditional line 74).

both gcc and clang support AddressSanitizer 
(https://en.wikipedia.org/wiki/AddressSanitizer). 
On those two compilers, all you have to do is compile with the 
`-fsanitize=address` command-line option.

## `string` Manipulation

Find substring position:

```cpp
string s = "aa", ss = "aabbaa";
cout << ss.find(s) << endl;      // 0
cout << ss.find(s, 2) << endl;   // 4
```

Slicing (substrings):

```cpp
string word = "0123456789";
cout << word.substr(0, 3) << endl;  // 012
cout << word.substr(1, 3) << endl;  // 123
cout << word.substr(3) << endl;     //3456789
```

## JS `map`

```js
const array1 = [1, 4, 9, 16];
const map1 = array1.map((x) => x * 2);

console.log(map1);
// Expected output: Array [2, 8, 18, 32]
```