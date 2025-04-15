#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
  int i, max = arr[0];

  // Find max value
  for (i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];

  // Create count array
  int *count = (int *)calloc(max + 1, sizeof(int));

  // Store count of each element
  for (i = 0; i < n; i++)
    count[arr[i]]++;

  // Output sorted values
  int index = 0;
  for (i = 0; i <= max; i++)
    while (count[i]-- > 0)
      arr[index++] = i;

  free(count);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("Original array: ");
  printArray(arr, n);

  countingSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);
  return 0;
}
