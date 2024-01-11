#include "utils.h"

void print_usage(const char *argv[]) {
    fprintf(stderr, "Usage: %s <algorithm>\n", argv[0]);
    fprintf(stderr, "1 - Bubble sort\n");
    fprintf(stderr, "2 - Insertion sort\n");
    fprintf(stderr, "3 - Selection sort\n");
    fprintf(stderr, "4 - Merge sort\n");
    fprintf(stderr, "5 - Quick sort\n");
}

void print_test_result(const bool result, const char message[]) {
    result ?
    fprintf(stdout, "\033[0;32m✅ PASS\033[0m\t%s", message) :
    fprintf(stderr, "\033[1;31m❌ FAIL\033[0m\t%s", message);
}

bool is_sorted(const int array[], const size_t size) {
    bool sorted = true;
    for (int i = 1; i < size && sorted; ++i) {
        sorted = array[i-1] <= array[i];
    }
    return sorted;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min(const int array[], const size_t size) {
    int min = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int max(const int array[], const size_t size) {
    int max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void random(int array[], const size_t size, const int low, const int high) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i] = low + rand() % (1 + high - low);
    }
}
