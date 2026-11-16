
Cumulative Median
=================

A Python package for efficient cumulative median computation,
implemented in C++ and exposed to Python using pybind11.

Installation
------------

Install the package from PyPI:

.. code-block:: bash

   pip install cum-median

Usage
-----

.. code-block:: python

   import numpy as np
   from cum_median import cumulative_median

   values = np.array([2, 3, 0, 1, 5], dtype=float)
   medians = cumulative_median(values)
   print(medians)

Expected output:

.. code-block:: text

   [2.  2.5 2.  1.5 2. ]

API Reference
-------------

.. autofunction:: cum_median.cumulative_median
