#include <stdbool.h>
#include <stdio.h>

void oddEvenSort(int arr[], int n) {
  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;

    // Fase ímpar (índices ímpares)
    for (int i = 1; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        isSorted = false;
      }
    }

    // Fase par (indices pares)
    for (int i = 0; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        isSorted = false;
      }
    }
  }
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

  oddEvenSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);
  return 0;
}
