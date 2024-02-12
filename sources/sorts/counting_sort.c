#include "utils.h"

void counting_sort(int array[], const size_t size, SDL_Renderer* renderer) {

    const int minimum_value = min(array, size);
    const int maximum_value = max(array, size);

    const size_t range_value = maximum_value - minimum_value + 1;
    int *counter = calloc(range_value, sizeof(int));

    for (int i = 0; i < size; ++i) {
        ++counter[array[i] - minimum_value];
    }

    int index = 0;
    int value = 0;

    while (index < size && value < range_value) {
        if (counter[value] > 0) {
            --counter[value];
            array[index++] = value + minimum_value;
            draw(array, size, renderer);
        } else {
            ++value;
        }
    }

    free(counter);
}
