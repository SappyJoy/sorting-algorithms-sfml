//
// Created by sappy-joy on 26/01/2021.
//

#include "algorithms.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
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