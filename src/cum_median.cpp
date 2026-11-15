
#include "cum_median.h"

#include <iterator>
#include <set>

int cumulative_median(
    const double* values_ptr,
    const int size,
    double* output_ptr
) {
    std::set<double> sorted_values;
    std::set<double>::iterator median_it;

    for (int index = 0; index < size; ++index) {
        const double value = values_ptr[index];
        const auto insertion = sorted_values.insert(value);

        if (!insertion.second) {
            return ERROR_DUPLICATE_VALUES;
        }

        if (index == 0) {
            median_it = insertion.first;
        } else if (sorted_values.size() % 2 == 0) {
            if (value < *median_it) {
                --median_it;
            }
        } else if (value > *median_it) {
            ++median_it;
        }

        if (sorted_values.size() % 2 == 0) {
            const auto next_it = std::next(median_it);
            output_ptr[index] =
                *median_it / 2.0 + *next_it / 2.0;
        } else {
            output_ptr[index] = *median_it;
        }
    }

    return SUCCESS;
}
