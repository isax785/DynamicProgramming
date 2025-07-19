# Readme

- [Readme](#readme)
- [Notebook Utils](#notebook-utils)

---

Coding repository focused on **Dynamic Programming**: practical examples and exercises based on problems related to the topic.

Purposes of this repo:

1. training on dynamic programming to consolidate the patterns with the aim of easing and speeding-up future coding;
2. strenghten known programming languages, e.g. `Python`, `C++`, `Cython`;
3. learn new programming languages, e.g. `Rust`, `Elixir`.

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