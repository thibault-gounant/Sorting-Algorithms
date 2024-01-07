#include "utils.h"

void insertion_sort(Graphics* graphics, int array[], const size_t size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j > 0 && array[j-1] > array[j]; --j) {
            swap(&array[j-1], &array[j]);
        }
    }
}
