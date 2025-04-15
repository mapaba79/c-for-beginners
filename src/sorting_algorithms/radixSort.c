#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void countingSortForRadix(int arr[], int n, int exp) {
  int output[n];
  int count[10] = {0};

  // Count occurrences based on digit at exp place
  for (int i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  // Cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Build the output array (stable sort)
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[--count[digit]] = arr[i];
  }

  // Copy output to original array
  for (int i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int n) {
  int max = getMax(arr, n);
  for (int exp = 1; max / exp > 0; exp *= 10)
    countingSortForRadix(arr, n, exp);
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

  radixSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
