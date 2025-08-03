# Readme

- [Readme](#readme)
- [Tasks](#tasks)
- [Notebook Utils](#notebook-utils)

---

> **Repetition** is the key.

Coding repository focused on **Dynamic Programming**: practical examples and exercises based on problems related to the topic.

Aims of this repo:

1. **speficific**
   1. training on dynamic programming to consolidate the patterns with the aim of easing and speeding-up future coding;
   2. strenghten known programming languages, e.g. `Python`, `C++`, `Cython`;
   3. learn new programming languages, e.g. `Rust`, `Elixir`.
2. **general**
   1. train your future self;
   2. speed-up and ease code reading and comprehension;
   3. power-up lateral thinking for problem solving, i.e. learn new solving structures;
   4. fisugre out visual representation of the solution;
   5. strenghten knowledge of time/space complexity, i.e. `O(n)`.

# Tasks

[Dynamic Programming Notebook](./ntb/dev_dynamic_programming.ipynb)

- [ ] Maximum Subarray
  - [ ] `#u` apply the **diviede and conquer** approach
  - [ ] `#a` derive the sequence of numbers whose sum is the maximum value
- [ ] Paths
  - [ ] `#a` `GridTraveler` implementations


# Notebook Utils

First cell:

```python
%load_ext autoreload
%autoreload 2

import os
import sys

CWD = os.path.abspath('')
sys.path.append(os.path.dirname(CWD))
```