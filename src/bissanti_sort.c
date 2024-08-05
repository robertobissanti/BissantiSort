/**
 * @file bissanti_sort.c
 * @brief Implementation file for BissantiSort algorithm.
 * 
 * BissantiSort is an innovative sorting algorithm that combines 
 * the benefits of PowerSort and TimSort to optimize the sorting 
 * of partially ordered arrays.
 * 
 * @date 2024-08-04
 * 
 * @author 
 * Roberto Bissanti
 * roberto.bissanti@gmail.com
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


#include "../include/bissanti_sort.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int start;
  int end;
} Run;

typedef struct {
  Run *runs;
  int count;
} RunList;

RunList detectRuns(int *array, int length) {
  RunList runList;
  runList.runs = (Run *)malloc(length * sizeof(Run));
  runList.count = 0;

  if (length == 0)
    return runList;

  int start = 0;
  for (int i = 1; i < length; i++) {
    if (array[i - 1] > array[i]) {
      runList.runs[runList.count].start = start;
      runList.runs[runList.count].end = i;
      runList.count++;
      start = i;
    }
  }
  runList.runs[runList.count].start = start;
  runList.runs[runList.count].end = length;
  runList.count++;

  return runList;
}

void insertionSort(int *array, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int temp = array[i];
    int j = i - 1;
    while (j >= left && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = temp;
  }
}

void merge(int *array, int start, int mid, int end) {
  int leftSize = mid - start;
  int rightSize = end - mid;
  int *left = (int *)malloc(leftSize * sizeof(int));
  int *right = (int *)malloc(rightSize * sizeof(int));

  for (int i = 0; i < leftSize; i++)
    left[i] = array[start + i];
  for (int i = 0; i < rightSize; i++)
    right[i] = array[mid + i];

  int i = 0, j = 0, k = start;
  while (i < leftSize && j < rightSize) {
    if (left[i] <= right[j]) {
      array[k++] = left[i++];
    } else {
      array[k++] = right[j++];
    }
  }
  while (i < leftSize) {
    array[k++] = left[i++];
  }
  while (j < rightSize) {
    array[k++] = right[j++];
  }

  free(left);
  free(right);
}

int calculatePower(Run run) { return run.end - run.start; }

int shouldMerge(Run run1, Run run2, int totalRuns) {
  if (totalRuns == 2) {
    return 1; // bypass the condition if there are only two runs
  } else {
    int power1 = calculatePower(run1);
    int power2 = calculatePower(run2);

    return power1 <= power2;
  }
}

void mergeRuns(int *array, RunList *runList) {
  while (runList->count > 1) {
    RunList newRunList;
    newRunList.runs = (Run *)malloc(runList->count * sizeof(Run));
    newRunList.count = 0;

    int i = 0;
    while (i < runList->count) {
      if (i + 1 < runList->count &&
          shouldMerge(runList->runs[i], runList->runs[i + 1], runList->count)) {
        int start = runList->runs[i].start;
        int mid = runList->runs[i].end;
        int end = runList->runs[i + 1].end;
        merge(array, start, mid, end);
        newRunList.runs[newRunList.count].start = start;
        newRunList.runs[newRunList.count].end = end;
        newRunList.count++;
        i += 2;
      } else {
        newRunList.runs[newRunList.count] = runList->runs[i];
        newRunList.count++;
        i++;
      }
    }

    free(runList->runs);
    *runList = newRunList;
  }
}

void bissantiSort(int *array, int length) {
  RunList runList = detectRuns(array, length);

  for (int i = 0; i < runList.count; i++) {
    insertionSort(array, runList.runs[i].start, runList.runs[i].end - 1);
  }

  mergeRuns(array, &runList);
  free(runList.runs);
}