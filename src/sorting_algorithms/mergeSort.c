#include <stdio.h>

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Temporary arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];

  // Merge the temp arrays back into arr[left...right]
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of L[], if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[], if any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // Recursively sort first abd second halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Function to print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d; ", arr[i]);
  printf("\n");
}

// Main function
int main() {
  int n;

  // Ask the user for the array size
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n]; // Declare an array of size 'n'

  // Get user input for the array elements
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
