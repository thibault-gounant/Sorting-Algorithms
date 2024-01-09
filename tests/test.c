#define SDL_MAIN_HANDLED

#include "sorts.h"
#include "utils.h"

#include <assert.h>


static void empty_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with no element\n");
    assert(sorted);
}

static void single_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {0};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with single element\n");
    assert(sorted);
}

static void ascending_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with elements sorted in ascending order\n");
    assert(sorted);
}

static void descending_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with elements sorted in descending order\n");
    assert(sorted);
}

static void negative_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {0,1,-2,3,4,-5,6,7,-8,9};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with negative elements\n");
    assert(sorted);
}

static void duplicate_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {0,1,7,3,4,4,6,7,2,9};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with duplicated elements\n");
    assert(sorted);
}

static void randomize_array_is_sorted(void (*algorithm)(Graphics*, int[], size_t)) {
    int array[] = {5,1,4,9,2,0,6,7,8,3};
    const size_t size = size(array);
    (algorithm)(NULL, array, size);
    const bool sorted = is_sorted(array, size);
    print_test_result(sorted, "Array with randomized elements\n");
    assert(sorted);
}

static void test_runner(void (*algorithm)(Graphics*, int[], size_t)) {
    empty_array_is_sorted(algorithm);
    single_array_is_sorted(algorithm);
    ascending_array_is_sorted(algorithm);
    descending_array_is_sorted(algorithm);
    negative_array_is_sorted(algorithm);
    duplicate_array_is_sorted(algorithm);
    randomize_array_is_sorted(algorithm);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        print_usage(argv);
        return EXIT_FAILURE;
    }

    const int algorithm = atoi(argv[1]);

    switch (algorithm) {
        case BUBBLE_SORT:
            printf("1 - Bubble sort\n");
            test_runner(&bubble_sort);
            break;
        case INSERTION_SORT:
            printf("2 - Insertion sort\n");
            test_runner(&insertion_sort);
            break;
        case SELECTION_SORT:
            printf("3 - Selection sort\n");
            test_runner(&selection_sort);
            break;
        case MERGE_SORT:
            printf("4 - Merge sort\n");
            test_runner(&merge_sort);
            break;
        default:
            print_usage(argv);
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
