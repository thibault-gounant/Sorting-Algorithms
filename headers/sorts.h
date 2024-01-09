#ifndef SORTS_H
#define SORTS_H

#include "utils.h"

enum Sorts {
    BUBBLE_SORT = 1,
    INSERTION_SORT = 2,
    SELECTION_SORT = 3,
    MERGE_SORT = 4,
};

void bubble_sort(Graphics* graphics, int array[], const size_t size);
void insertion_sort(Graphics* graphics, int array[], const size_t size);
void selection_sort(Graphics* graphics, int array[], const size_t size);
void merge_sort(Graphics* graphics, int array[], const size_t size);

#endif
