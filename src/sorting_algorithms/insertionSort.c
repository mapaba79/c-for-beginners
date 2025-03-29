#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
  int i, key, j;

  // Traverse through 1 to n-1
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key,
    // to one position ahead
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    // Place the key in the correct position
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;

  // Ask the user for the array size
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(arr, n);

  insertionSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
