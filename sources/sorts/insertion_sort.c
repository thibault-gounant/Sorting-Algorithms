#include "utils.h"

void insertion_sort(int array[], const size_t size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && array[j-1] > array[j]; --j) {
            swap(&array[j-1], &array[j]);
        }
    }
}
