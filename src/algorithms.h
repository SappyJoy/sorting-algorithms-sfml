//
// Created by sappy-joy on 26/01/2021.
//

/*
 * Different sorting algorithms
 * Each method returns a vector of pairs that need to be swapped in order to sort the array
 * */

#ifndef SORTING_ALGORITHMS_SRC_ALGORITHMS_H_
#define SORTING_ALGORITHMS_SRC_ALGORITHMS_H_
#include <vector>

std::vector<std::pair<unsigned, unsigned>>* bubble_sort(int *array, size_t size);

std::vector<std::pair<unsigned, unsigned>>* selection_sort(int *array, size_t size);

std::vector<std::pair<unsigned, unsigned>>* recursive_bubble_sort(int *array, size_t size);

std::vector<std::pair<unsigned, unsigned>>* insertion_sort(int *array, size_t size);

std::vector<std::pair<unsigned, unsigned>>* recursive_insertion_sort(int *array, size_t size);

std::vector<std::pair<unsigned, unsigned>>* merge_sort(int *array, size_t size);


#endif //SORTING_ALGORITHMS_SRC_ALGORITHMS_H_
