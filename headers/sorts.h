#ifndef SORTS_H
#define SORTS_H

#include "utils.h"

enum Sorts {
    BUBBLE_SORT = 1,
    INSERTION_SORT = 2,
    SELECTION_SORT = 3,
    MERGE_SORT = 4,
    QUICK_SORT = 5,
    COUNTING_SORT  = 6
};

void bubble_sort(int array[], size_t size, SDL_Renderer* renderer);
void insertion_sort(int array[], size_t size, SDL_Renderer* renderer);
void selection_sort(int array[], size_t size, SDL_Renderer* renderer);
void merge_sort(int array[], size_t size, SDL_Renderer* renderer);
void quick_sort(int array[], size_t size, SDL_Renderer* renderer);
void counting_sort(int array[], size_t size, SDL_Renderer* renderer);

#endif
