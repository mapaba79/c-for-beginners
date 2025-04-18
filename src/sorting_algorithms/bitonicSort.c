#include <limits.h> // Include for INT_MAX
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ASCENDING 1
#define DESCENDING 0
#define DUMMY_VALUE INT_MAX // A value larger than any expected input

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform the compare and swap operation
void bitonicCompare(int arr[], int low, int cnt, int dir) {
  int k = cnt / 2;
  for (int i = low; i < low + k; i++) {
    if (dir == (arr[i] > arr[i + k])) {
      swap(&arr[i], &arr[i + k]);
    }
  }
}

// Recursive function to sort a bitonic sequence
void bitonicMerge(int arr[], int low, int cnt, int dir) {
  if (cnt > 1) {
    int k = cnt / 2;
    bitonicCompare(arr, low, cnt, dir);
    bitonicMerge(arr, low, k, dir);
    bitonicMerge(arr, low + k, k, dir);
  }
}

// Recursive function to generate bitonic sequence
void bitonicSort(int arr[], int low, int cnt, int dir) {
  if (cnt > 1) {
    int k = cnt / 2;

    // Sort in ascending order
    bitonicSort(arr, low, k, ASCENDING);

    // Sort in descending order
    bitonicSort(arr, low + k, k, DESCENDING);

    // Merge the entire sequence in given direction
    bitonicMerge(arr, low, cnt, dir);
  }
}

// Function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(arr, n);

  // Find the next power of 2
  int powerOfTwoSize = 1;
  while (powerOfTwoSize < n) {
    powerOfTwoSize *= 2;
  }

  // Create a padded array
  int *paddedArr = (int *)malloc(powerOfTwoSize * sizeof(int));
  if (paddedArr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    free(arr);
    return 1;
  }

  // Copy the original array and pad with dummy values
  for (int i = 0; i < n; i++) {
    paddedArr[i] = arr[i];
  }
  for (int i = n; i < powerOfTwoSize; i++) {
    paddedArr[i] = DUMMY_VALUE;
  }

  bitonicSort(paddedArr, 0, powerOfTwoSize, ASCENDING);

  printf("Sorted array: ");
  // Print only the original number of elements, ignoring the padding
  for (int i = 0; i < n; i++) {
    printf("%d ", paddedArr[i]);
  }
  printf("\n");

  free(arr);
  free(paddedArr);
  return 0;
}
