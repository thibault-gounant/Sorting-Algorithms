#include "utils.h"

void selection_sort(int array[], const size_t size) {
    for (int i = 0; i < size; ++i) {
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[index] > array[j]) {
                index = j;
            }
        }
        if (index != i) {
            swap(&array[i], &array[index]);
        }
    }
}
