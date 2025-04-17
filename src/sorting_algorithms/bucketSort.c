#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Helper for insertion sort (used within buckets)
void insertionSort(float arr[], int n) {
  for (int i = 1; i < n; i++) {
    float key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
      arr[j + 1] = arr[j--];
    arr[j + 1] = key;
  }
}

void bucketSort(float arr[], int n) {
  float buckets[BUCKET_COUNT][n];
  int bucketSizes[BUCKET_COUNT] = {0};

  // Place elements into buckets
  for (int i = 0; i < n; i++) {
    int bucketIndex = (int)(arr[i] * BUCKET_COUNT);
    buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
  }

  // Sort each bucket and concatenate
  int index = 0;
  for (int i = 0; i < BUCKET_COUNT; i++) {
    insertionSort(buckets[i], bucketSizes[i]);
    for (int j = 0; j < bucketSizes[i]; j++)
      arr[index++] = buckets[i][j];
  }
}

void printArray(float arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%.2f ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  float arr[n];
  printf("Enter %d float numbers in range [0, 1]: ", n);
  for (int i = 0; i < n; i++)
    scanf("%f", &arr[i]);

  printf("Original array: ");
  printArray(arr, n);

  bucketSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);
  return 0;
}
