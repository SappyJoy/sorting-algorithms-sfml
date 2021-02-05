//
// Created by sappy-joy on 26/01/2021.
//
#include <iostream>
#include "algorithms.h"

/* Utilities */
int min(int x, int y) { return (x<y)? x :y; }

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

std::vector<std::pair<unsigned, unsigned>>* insertion_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;

  int key;
  size_t j = 1;
  for (size_t i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      moves->push_back(std::make_pair(j + 1, j));
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }

  return moves;
}

void recursive_insertion_sort_helper(int *array, size_t size, std::vector<std::pair<unsigned, unsigned>> *moves) {

  if (size == 1)
    return;

  recursive_insertion_sort_helper(array, size - 1, moves);

  int key = array[size - 1];
  size_t j = size - 2;
  while (j >= 0 && array[j] > key) {
    moves->push_back(std::make_pair(j + 1, j));
    array[j + 1] = array[j];
    j--;
  }
  array[j + 1] = key;
}

std::vector<std::pair<unsigned, unsigned>>* recursive_insertion_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;
  recursive_insertion_sort_helper(array, size, moves);
  return moves;
}

void merge(int *array, size_t l, size_t m, size_t r, std::vector<std::pair<unsigned, unsigned>> *moves) {
  size_t n1 = m - l + 1;
  size_t n2 = r - m;

  // Temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays
  for (size_t i = 0; i < n1; i++)
    L[i] = array[l + i];
  for (size_t i = 0; i < n2; i++)
    R[i] = array[m + i + 1];

  // Merge temp arrays into initial array
  size_t i = 0;
  size_t j = 0;
  size_t k = l;
  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      // Сдвинуть весь массив L на m + j + 1 - k вправо
      for (size_t shift = m + j + 1; shift > k; shift--) {
        moves->push_back(std::make_pair(shift, shift - 1));
      }
      j++;
    }
    k++;
  }

  // Copy remaining elements
  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort_helper(int *array, size_t l, size_t r, std::vector<std::pair<unsigned, unsigned>> *moves) {
  if (r <= l)
    return;

  size_t middle = l + (r - l) / 2;
  merge_sort_helper(array, l, middle, moves);
  merge_sort_helper(array, middle + 1, r, moves);
  merge(array, l, middle, r, moves);
}

std::vector<std::pair<unsigned, unsigned>>* merge_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;
  merge_sort_helper(array, 0, size, moves);
  return moves;
}

std::vector<std::pair<unsigned, unsigned>>* iterative_merge_sort(int *array, size_t size) {
  auto moves = new std::vector<std::pair<unsigned, unsigned>>;

  for (size_t cur_size = 1; cur_size <= size -1; cur_size *= 2) {
    for (size_t left_start = 0; left_start <= size - 1; left_start += 2 * cur_size) {
      size_t mid = min(left_start + cur_size - 1, size - 1);
      int right_end = min(left_start + 2 * cur_size - 1, size - 1);
      merge(array, left_start, mid, right_end, moves);
    }
  }

  return moves;
}