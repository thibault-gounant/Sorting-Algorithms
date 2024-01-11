#include "utils.h"

static int pivot(int array[], const size_t size, int start, int end, SDL_Renderer* renderer) {

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
    draw(array, size, renderer);
    return array[end];
}

static int partition(int array[], const size_t size, int start, int end, SDL_Renderer* renderer) {

    int value = pivot(array, size, start, end, renderer);
    int index = start;

    for (int i = start; i <= end; ++i) {
        if (array[i] < value) {
            swap(&array[i], &array[index++]);
            draw(array, size, renderer);
        }
    }

    swap(&array[index], &array[end]);
    draw(array, size, renderer);
    return index;
}

static void quick_sort_helper(int array[], const size_t size, int start, int end, SDL_Renderer* renderer) {
    if (start < end) {
        int pivot_index = partition(array, size, start, end, renderer);
        quick_sort_helper(array, size, start, pivot_index - 1, renderer);
        quick_sort_helper(array, size, pivot_index + 1, end, renderer);
    }
}

void quick_sort(int array[], const size_t size, SDL_Renderer* renderer) {
    quick_sort_helper(array, size, 0, size - 1, renderer);
}
