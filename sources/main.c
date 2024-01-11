#define SDL_MAIN_HANDLED

#include "sorts.h"
#include "utils.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        print_usage(argv);
        return EXIT_FAILURE;
    }

    void (*sort)(int[], size_t, SDL_Renderer*);
    const int algorithm = atoi(argv[1]);

    switch (algorithm) {
        case BUBBLE_SORT:
            printf("Bubble sort\n");
            sort = &bubble_sort;
            break;
        case INSERTION_SORT:
            printf("Insertion sort\n");
            sort = &insertion_sort;
            break;
        case SELECTION_SORT:
            printf("Selection sort\n");
            sort = &selection_sort;
            break;
        case MERGE_SORT:
            printf("Merge sort\n");
            sort = &merge_sort;
            break;
        case QUICK_SORT:
            printf("Quick sort\n");
            sort = &quick_sort;
            break;
        default:
            print_usage(argv);
            return EXIT_FAILURE;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL init error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Sorting Algorithms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        fprintf(stderr, "Window creation error: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Renderer creation error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    int array[SIZE];
    random(array, SIZE, 0, HEIGHT);
    bool sorted = false;

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        if (!sorted) {
            sorted = is_sorted(array, SIZE);
        }
        if (!sorted) {
            sort(array, SIZE, renderer);
        }

        draw(array, SIZE, renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
