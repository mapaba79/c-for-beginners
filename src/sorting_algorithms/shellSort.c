#include <stdio.h>

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
  // Start with a large gap and reduce the gap in each iteraion
  for (int gap = n / 2; gap > 0; gap /= 2) {
    // Do a gapped insertion sort for this gap size.
    // The fisrt gap elements arr[0...gap-1] are already in gapped order
    // Keep adding one more element until the entire array is gap sorted
    for (int i = gap; i < n; i++) {
      // Save arr[i] in temp and make space for it
      int temp = arr[i];

      // Shift earlier gap-sorted elements up until
      // the correct position for arr[i] is found
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];

      // Put temp (the original arr[i]) in its correct position
      arr[j] = temp;
    }
  }
}

// Helper function to print the array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {12, 24, 54, 3, 17};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  shellSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
