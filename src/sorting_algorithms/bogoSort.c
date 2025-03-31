#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to check if an array is sorted
bool is_sorted(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

// Function to randomly shuffle an array
void shuffle(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    swap(&arr[i], &arr[j]);
  }
}

// The "stupid" sort: Bogo sort
void bogo_sort(int arr[], int n) {
  while (!is_sorted(arr, n)) {
    shuffle(arr, n);
  }
}

int main() {
  int arr[] = {3, 7, 12, 4, 10, 2, 8, 9, 0, 5, 11, 6, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Seed the random number generator
  srand(time(NULL));

  bogo_sort(arr, n);

  printf("Sorted array (hopefully!): ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
