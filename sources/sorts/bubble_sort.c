#include "utils.h"

void bubble_sort(int array[], const size_t size, SDL_Renderer* renderer) {
    bool sorted = false;
    for (int i = 0; i < size && !sorted; ++i) {
        sorted = true;
        for (int j = 1; j < size - i; ++j) {
            if (array[j-1] > array[j]) {
                swap(&array[j-1], &array[j]);
                draw(array, size, renderer);
                sorted = false;
            }
        }
    }
}
