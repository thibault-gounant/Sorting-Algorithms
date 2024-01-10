#include "utils.h"

static int pivot(int array[], int start, int end) {

    int middle = start + (end - start) / 2;

    if (array[start] > array[middle]) {
        swap(&array[start], &array[middle]);
    }
    if (array[start] > array[end]) {
        swap(&array[start], &array[end]);
    }
    if (array[middle] > array[end]) {
        swap(&array[middle], &array[end]);
    }

    swap(&array[middle], &array[end]);
    return array[end];
}

static int partition(int array[], int start, int end) {

    int value = pivot(array, start, end);
    int index = start;

    for (int i = start; i <= end; ++i) {
        if (array[i] < value) {
            swap(&array[i], &array[index++]);
        }
    }

    swap(&array[index], &array[end]);
    return index;
}

static void quick_sort_helper(int array[], int start, int end) {
    if (start < end) {
        int pivot_index = partition(array, start, end);
        quick_sort_helper(array, start, pivot_index - 1);
        quick_sort_helper(array, pivot_index + 1, end);
    }
}

void quick_sort(int array[], const size_t size) {
    quick_sort_helper(array, 0, size - 1);
}
