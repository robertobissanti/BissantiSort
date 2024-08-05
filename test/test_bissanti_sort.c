/**
 * @file test_bissanti_sort.c
 * @brief Test file for BissantiSort algorithm.
 * 
 * This file contains test cases to verify the correctness and 
 * performance of the BissantiSort algorithm developed by Roberto Bissanti.
 * 
 * @date 2024-08-04
 * 
 * @author 
 * Roberto Bissanti
 * roberto.bissanti@gmail.com
 * Alessandro Bissanti
 * alessandro.bissanti@gmail.com
 *
 * @license
 * GNU General Public License v3.0
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
 
#include <stdio.h>
#include <assert.h>
#include "../include/bissanti_sort.h"

void test_sorted_array() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array) / sizeof(array[0]);
    bissantiSort(array, length);
    for (int i = 0; i < length - 1; i++) {
        assert(array[i] <= array[i + 1]);
    }
    printf("Test sorted_array passed!\n");
}

void test_reverse_sorted_array() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int length = sizeof(array) / sizeof(array[0]);
    bissantiSort(array, length);
    for (int i = 0; i < length - 1; i++) {
        assert(array[i] <= array[i + 1]);
    }
    printf("Test reverse_sorted_array passed!\n");
}

void test_random_array() {
    int array[] = {9, 10, 12, 14, 27, 4, 3, 1, 7, 5, 6, 2, 8};
    int length = sizeof(array) / sizeof(array[0]);
    bissantiSort(array, length);
    for (int i = 0; i < length - 1; i++) {
        assert(array[i] <= array[i + 1]);
    }
    printf("Test random_array passed!\n");
}

int main() {
    test_sorted_array();
    test_reverse_sorted_array();
    test_random_array();
    printf("All tests passed!\n");
    return 0;
}