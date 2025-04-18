#include <stdio.h>
#include <stdlib.h>

void stoogeSort(int arr[], int l, int h) {
  if (arr[l] > arr[h]) {
    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
  }

  if ((h - l + 1) > 2) {
    int t = (h - l + 1) / 3;
    stoogeSort(arr, l, h - t);
    stoogeSort(arr, l + t, h);
    stoogeSort(arr, l, h - t);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Quantos números deseja ordenar? ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Número inválido de elementos.\n");
    return 1;
  }

  int *arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Erro de alocação de memória.\n");
    return 1;
  }

  printf("Digite os %d números:\n", n);
  for (int i = 0; i < n; i++) {
    printf("Elemento %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  stoogeSort(arr, 0, n - 1);

  printArray(arr, n);

  free(arr);
  return 0;
}
