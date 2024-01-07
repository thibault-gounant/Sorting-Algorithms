#ifndef SORTS_H
#define SORTS_H

#include "utils.h"

enum Sorts {
    BUBBLE_SORT = 1,
    INSERTION_SORT = 2,
};

void bubble_sort(int array[], const size_t size);
void insertion_sort(int array[], const size_t size);

#endif
