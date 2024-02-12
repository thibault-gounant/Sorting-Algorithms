#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#define WIDTH 1000
#define HEIGHT 600
#define SIZE 300

#include <stdlib.h>
#include <stdbool.h>

#define size(array) (sizeof(array) / sizeof((array)[0]))

void print_usage(const char *argv[]);

bool is_sorted(const int array[], size_t size);

void swap(int *a, int *b);

int min(const int array[], size_t size);
int max(const int array[], size_t size);

void random(int array[], size_t size, int low, int high);

void draw(int array[], size_t size, SDL_Renderer* renderer);

#endif
