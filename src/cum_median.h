
#ifndef CUM_MEDIAN_H
#define CUM_MEDIAN_H

#define SUCCESS 0
#define ERROR_DUPLICATE_VALUES 1

int cumulative_median(
    const double* values_ptr,
    const int size,
    double* output_ptr
);

#endif
