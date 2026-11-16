
# Cumulative Median with C++ and pybind11

A Python package for efficient cumulative median computation,
implemented in C++ and exposed to Python using pybind11.

The package computes the median after each new value in an input
sequence using an ordered `std::set`.

## Features

- C++17 implementation with Python bindings through pybind11
- Cumulative median computation in O(n log n) time
- NumPy array support
- Input validation and duplicate detection
- Precompiled wheels for Windows, Linux, and macOS
- Automated testing with pytest and GitHub Actions
- Documentation hosted on Read the Docs

## Installation

Install the package directly from PyPI:

```bash
pip install cum-median
```

## Usage

```python
import numpy as np
from cum_median import cumulative_median

values = np.array([2, 3, 0, 1, 5], dtype=float)
medians = cumulative_median(values)

print(medians)
```

Expected output:

```text
[2.  2.5 2.  1.5 2. ]
```

## How It Works

For each new element, the algorithm maintains the values in sorted
order and computes the median of the current prefix.

| Input prefix | Cumulative median |
|---|---|
| [2] | 2.0 |
| [2, 3] | 2.5 |
| [2, 3, 0] | 2.0 |
| [2, 3, 0, 1] | 1.5 |
| [2, 3, 0, 1, 5] | 2.0 |

The implementation uses a `std::set` and a median iterator to
achieve O(n log n) total time complexity.

## Input Requirements

The input must be:

- A non-empty, one-dimensional array
- Composed of finite numeric values
- Free of duplicate values

Invalid inputs raise `ValueError` or `RuntimeError`.

## Testing

Run the test suite from the project directory:

```bash
python -m pytest tests/ -v
```

## Documentation

Full documentation is available on Read the Docs:

https://pybind11-cumulative-median.readthedocs.io/en/latest/

## Continuous Integration

GitHub Actions uses cibuildwheel to build and test the package
on Windows, Linux, and macOS.

The compiled wheels are published to PyPI using Trusted Publishing.

## Links

- GitHub: https://github.com/AdamG-wizz/pybind11-cumulative-median
- PyPI: https://pypi.org/project/cum-median/
- Documentation: https://pybind11-cumulative-median.readthedocs.io/en/latest/

## License

No license has been specified for this project.
