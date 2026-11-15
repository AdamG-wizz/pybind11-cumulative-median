
import numpy as np
import pytest

from cum_median import cumulative_median


def test_slide_example():
    values = np.array([2, 3, 0, 1, 5], dtype=float)
    expected = np.array([2, 2.5, 2, 1.5, 2])
    actual = cumulative_median(values)
    np.testing.assert_array_equal(actual, expected)


def test_duplicate_values():
    values = np.array([2, 3, 2], dtype=float)
    with pytest.raises(RuntimeError, match="duplicate values"):
        cumulative_median(values)


def test_single_value():
    values = np.array([7.0])
    actual = cumulative_median(values)
    np.testing.assert_array_equal(actual, values)


def test_empty_array():
    values = np.array([], dtype=float)
    with pytest.raises(ValueError, match="empty"):
        cumulative_median(values)


def test_non_finite_values():
    for invalid_value in [np.nan, np.inf, -np.inf]:
        values = np.array([2.0, invalid_value])
        with pytest.raises(ValueError, match="finite"):
            cumulative_median(values)


def test_multidimensional_array():
    values = np.array([[2.0, 3.0], [0.0, 1.0]])
    with pytest.raises(ValueError, match="one-dimensional"):
        cumulative_median(values)
