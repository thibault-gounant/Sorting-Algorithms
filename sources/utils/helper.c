#include "utils.h"


void print_usage(const char *argv[]) {
    fprintf(stderr, "Usage: %s <number>\n", argv[0]);
    fprintf(stderr, " - number 1 for bubble sort\n");
    fprintf(stderr, " - number 2 for insertion sort\n");
    fprintf(stderr, " - number 3 for selection sort\n");
    fprintf(stderr, " - number 4 for merge sort\n");
    fprintf(stderr, " - number 5 for quick sort\n");
}

void print_test_result(const bool result, const char message[]) {
    result ?
    fprintf(stdout, "\033[0;32m ✅ PASS \033[0m \t %s", message) :
    fprintf(stderr, "\033[1;31m ❌ FAIL \033[0m \t %s", message);
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
