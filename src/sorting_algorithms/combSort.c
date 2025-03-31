#include <stdbool.h>
#include <stdio.h>

// Function to get the next gap for comb sort
int getNextGap(int gap) {
  // Shrink gap by shrink factor
  gap = (gap * 10) / 13;
  if (gap < 1)
    return 1;
  return gap;
}

// Function to implement comb sort
void combSort(int arr[], int n) {
  // Initialize gap
  int gap = n;

  // Initialize sorted flag to false so the loop continues
  // until the array is sorted
  bool swapped = true;

  while (gap != 1 || swapped == true) {
    // Find next gap
    gap = getNextGap(gap);

    // Reset swapped flag for this iteration
    swapped = false;

    // Compare all elements with current gap
    for (int i = 0; i < n - gap; i++) {
      if (arr[i] > arr[i + gap]) {
        int temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = true;
      }
    }
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program to test comb sort
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

  printf("Array before sorting: ");
  printArray(arr, n);
  combSort(arr, n);
  printf("Array after sorting: ");
  printArray(arr, n);
  return 0;
}
