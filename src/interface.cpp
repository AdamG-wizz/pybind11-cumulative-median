
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>

#include <cmath>
#include <limits>
#include <stdexcept>

#include "cum_mediane.h"

namespace py = pybind11;

py::array_t<double> cumulative_median_python(
    py::array_t<double, py::array::c_style |
                        py::array::forcecast> values
) {
    const py::buffer_info input = values.request();

    if (input.ndim != 1) {
        throw std::invalid_argument(
            "Input must be one-dimensional"
        );
    }

    if (input.size == 0) {
        throw std::invalid_argument(
            "Input array must not be empty"
        );
    }

    if (input.size > std::numeric_limits<int>::max()) {
        throw std::invalid_argument(
            "Input array is too large"
        );
    }

    const auto* input_ptr =
        static_cast<const double*>(input.ptr);

    for (py::ssize_t index = 0; index < input.size; ++index) {
        if (!std::isfinite(input_ptr[index])) {
            throw std::invalid_argument(
                "Input values must be finite"
            );
        }
    }

    py::array_t<double> output(input.size);
    const py::buffer_info result = output.request();
    auto* output_ptr = static_cast<double*>(result.ptr);

    const int status = cum_mediane(
        input_ptr,
        static_cast<int>(input.size),
        output_ptr
    );

    if (status == ERROR_DONNEES_REPETEES) {
        throw std::runtime_error(
            "Input contains duplicate values"
        );
    }

    if (status != SUCCESS) {
        throw std::runtime_error(
            "Cumulative median computation failed"
        );
    }

    return output;
}

PYBIND11_MODULE(cum_median, module) {
    module.def(
        "cumulative_median",
        &cumulative_median_python,
        py::arg("values"),
        R"doc(
Compute cumulative medians of distinct values.

Parameters
----------
values : numpy.ndarray
    One-dimensional array of finite, distinct values.

Returns
-------
numpy.ndarray
    Median computed after each new value.

Raises
------
ValueError
    If the input array is invalid.
RuntimeError
    If the array contains duplicate values.
)doc"
    );
}
