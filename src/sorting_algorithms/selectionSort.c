#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
  int i, j, minIndex, temp;

  // Traverse through all array elements
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in the unsorted part of the array
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    // Swap the found minimum element with the element at index i
    if (minIndex != i) {
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

// Function to print the array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  selectionSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
