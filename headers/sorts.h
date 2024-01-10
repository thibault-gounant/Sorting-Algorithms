#ifndef SORTS_H
#define SORTS_H

#include "utils.h"

enum Sorts {
    BUBBLE_SORT = 1,
    INSERTION_SORT = 2,
    SELECTION_SORT = 3,
    MERGE_SORT = 4,
    QUICK_SORT = 5,
};

void bubble_sort(int array[], const size_t size);
void insertion_sort(int array[], const size_t size);
void selection_sort(int array[], const size_t size);
void merge_sort(int array[], const size_t size);
void quick_sort(int array[], const size_t size);

#endif
