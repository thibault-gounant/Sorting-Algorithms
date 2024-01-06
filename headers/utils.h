#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define size(array) (sizeof(array) / sizeof((array)[0]))

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} Graphics;

void print_usage(const char *argv[]);
void print_test_result(const bool result, const char message[]);
bool is_sorted(const int array[], const size_t size);
void swap(int *a, int *b);

#endif
