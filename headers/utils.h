#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size(array) (sizeof(array) / sizeof((array)[0]))

void print_usage(const char *argv[]);
void print_test_result(const bool result, const char message[]);
bool is_sorted(const int array[], const size_t size);
void swap(int *a, int *b);

#endif
