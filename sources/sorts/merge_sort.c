#include "utils.h"

static void merge(int array[], const size_t size, int start, int middle, int end, SDL_Renderer* renderer) {

    const size_t buffer_size = end - start + 1;
    int* buffer = malloc(buffer_size * sizeof(int));

    for (int i = start; i <= end; ++i) {
        buffer[i - start] = array[i];
    }

    int left = 0;
    int right = middle + 1 - start;

    for (int i = start; i <= end; ++i) {
        if (right >= buffer_size || (left < middle + 1 - start && buffer[left] < buffer[right])) {
            array[i] = buffer[left++];
        } else {
            array[i] = buffer[right++];
        }
        draw(array, size, renderer);
    }

    free(buffer);
}

static void merge_sort_helper(int array[], const size_t size, int start, int end, SDL_Renderer* renderer) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        merge_sort_helper(array, size, start, middle, renderer);
        merge_sort_helper(array, size, middle + 1, end, renderer);
        merge(array, size, start, middle, end, renderer);
    }
}

void merge_sort(int array[], const size_t size, SDL_Renderer* renderer) {
    merge_sort_helper(array, size, 0, size - 1, renderer);
}
