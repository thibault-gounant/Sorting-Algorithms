#define SDL_MAIN_HANDLED

#include "sorts.h"
#include "utils.h"

#include <assert.h>


static bool empty_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool single_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {0};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool ascending_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool descending_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool negative_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {0,1,-2,3,4,-5,6,7,-8,9};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool duplicate_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {0,1,7,3,4,4,6,7,2,9};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static bool randomize_array_is_sorted(void (*algorithm)(int[], size_t)) {
    int array[] = {5,1,4,9,2,0,6,7,8,3};
    const size_t size = size(array);
    (algorithm)(array, size);
    return is_sorted(array, size);
}

static void test_runner(void (*algorithm)(int[], size_t)) {

    bool empty = empty_array_is_sorted(algorithm);
    print_test_result(empty, "Empty array\n");

    bool single = single_array_is_sorted(algorithm);
    print_test_result(single, "Single element array\n");

    bool ascending = ascending_array_is_sorted(algorithm);
    print_test_result(ascending, "Ascending order array\n");

    bool descending = descending_array_is_sorted(algorithm);
    print_test_result(descending, "Descending order array\n");

    bool negative = negative_array_is_sorted(algorithm);
    print_test_result(negative, "Array with negative elements\n");

    bool duplicate = duplicate_array_is_sorted(algorithm);
    print_test_result(duplicate, "Array with duplicate elements\n");

    bool randomize = randomize_array_is_sorted(algorithm);
    print_test_result(randomize, "Randomized array\n");

    assert(empty && single && ascending && descending && negative && duplicate && randomize);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        print_usage(argv);
        return EXIT_FAILURE;
    }

    const int algorithm = atoi(argv[1]);

    switch (algorithm) {
        case BUBBLE_SORT:
            printf("Bubble sort\n");
            test_runner(&bubble_sort);
            break;
        case INSERTION_SORT:
            printf("Insertion sort\n");
            test_runner(&insertion_sort);
            break;
        case SELECTION_SORT:
            printf("Selection sort\n");
            test_runner(&selection_sort);
            break;
        default:
            print_usage(argv);
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
