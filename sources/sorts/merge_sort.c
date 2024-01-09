#include "utils.h"

static void merge(int array[], int start, int middle, int end) {
    int buffer[end - start + 1];
    for (int i = start; i <= end; ++i) {
        buffer[i - start] = array[i];
    }

    int left = 0;
    int right = middle + 1 - start;
    for (int i = start; i <= end; ++i) {
        if (right > end || (left < middle + 1 - start && buffer[left] < buffer[right])) {
            array[i] = buffer[left++];
        } else {
            array[i] = buffer[right++];
        }
    }
}

static void merge_sort_helper(int array[], int start, int end) {
    if (start < end) {
        int middle = start + (end-start) / 2;
        merge_sort_helper(array, start, middle);
        merge_sort_helper(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

void merge_sort(Graphics* graphics, int array[], const size_t size) {
    merge_sort_helper(array, 0, size-1);
}
