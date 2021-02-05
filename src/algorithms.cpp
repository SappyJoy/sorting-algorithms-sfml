//
// Created by sappy-joy on 26/01/2021.
//

#include "algorithms.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

std::vector<std::pair<unsigned, unsigned>>* selection_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;

  for (size_t i = 0; i < size - 1; i++) {
    int min = array[i];
    size_t min_idx = i;
    for (size_t j = i; j < size; j++) {
      if (array[j] < min) {
        min = array[j];
        min_idx = j;
      }
    }
    if (i != min_idx) {
      swap(&array[i], &array[min_idx]);
      moves->push_back(std::make_pair(i, min_idx));
    }
  }
  return moves;
}

std::vector<std::pair<unsigned, unsigned>>* bubble_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        moves->push_back(std::make_pair(j, j + 1));
      }
    }
  }
  return moves;
}

void recursive_bubble_sort_helper(int *array, size_t size, std::vector<std::pair<unsigned, unsigned>> *moves) {
  if (size == 1)
    return;
  for (size_t i = 0; i < size; i++) {
    if (array[i] > array[i + 1]) {
      swap(&array[i], &array[i + 1]);
      moves->push_back(std::make_pair(i, i + 1));
    }
  }
  recursive_bubble_sort_helper(array, size - 1, moves);
}

std::vector<std::pair<unsigned, unsigned>>* recursive_bubble_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;
  recursive_bubble_sort_helper(array, size, moves);
  return moves;
}