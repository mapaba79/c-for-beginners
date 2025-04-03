// Compilar com o parametro '-lm'

#include <math.h>
#include <stdio.h>

#define MIN_RUN 32 // Tamanho mínimo para uma run

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para encontrar o tamanho da próxima run ordenada
int countRun(int arr[], int n, int start) {
  int end = start + 1;
  if (end == n)
    return 1;

  // Verifica se a run é ascendente ou descendente
  if (arr[start] <= arr[end]) {
    while (end < n && arr[end - 1] <= arr[end])
      end++;
  } else {
    while (end < n && arr[end - 1] > arr[end])
      end++;
    // Inverte a run descendente para torná-la ascendente
    for (int i = start, j = end - 1; i < j; i++, j--)
      swap(&arr[i], &arr[j]);
  }
  return end - start;
}

// Função de Insertion Sort (para ordenar runs pequenas)
void insertionSortTim(int arr[], int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// Função de Merge (usada no Merge Sort e TimSort)
void merge(int arr[], int l, int m, int r) {
  int len1 = m - l + 1, len2 = r - m;
  int left[len1], right[len2];

  for (int i = 0; i < len1; i++)
    left[i] = arr[l + i];
  for (int i = 0; i < len2; i++)
    right[i] = arr[m + 1 + i];

  int i = 0, j = 0, k = l;
  while (i < len1 && j < len2) {
    if (left[i] <= right[j])
      arr[k++] = left[i++];
    else
      arr[k++] = right[j++];
  }
  while (i < len1)
    arr[k++] = left[i++];
  while (j < len2)
    arr[k++] = right[j++];
}

// Função principal do Timsort
void timsort(int arr[], int n) {
  // Ordena as runs individuais usando Insertion Sort
  for (int i = 0; i < n; i += MIN_RUN) {
    insertionSortTim(arr, i, fmin((i + MIN_RUN - 1), (n - 1)));
  }

  // Mescla as runs ordenadas em tamanhos crescentes
  for (int size = MIN_RUN; size < n; size = 2 * size) {
    for (int left = 0; left < n; left += 2 * size) {
      int mid = left + size - 1;
      int right = fmin((left + 2 * size - 1), (n - 1));
      if (mid < right)
        merge(arr, left, mid, right);
    }
  }
}

// Função para imprimir um array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d; ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {5, -5, 9,  2, -2, 8,  -9, 1,  -4, -1,
               4, 7,  -6, 3, 6,  -8, 0,  -3, -7};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array antes da ordenação: ");
  printArray(arr, n);

  timsort(arr, n);

  printf("Array depois da ordenação: ");
  printArray(arr, n);

  return 0;
}
