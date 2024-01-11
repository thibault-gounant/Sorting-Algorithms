#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#define WIDTH 1000
#define HEIGHT 600
#define SIZE 300

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define size(array) (sizeof(array) / sizeof((array)[0]))

void print_usage(const char *argv[]);
void print_test_result(const bool result, const char message[]);

bool is_sorted(const int array[], const size_t size);

void swap(int *a, int *b);

int min(const int array[], const size_t size);
int max(const int array[], const size_t size);

void random(int array[], const size_t size, const int low, const int high);

void draw(int array[], const size_t size, SDL_Renderer* renderer);

#endif
