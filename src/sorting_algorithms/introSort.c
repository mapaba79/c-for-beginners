// Compile com 'gcc introSort.c -o introSort -lm'
// para instruir o linker a incluir a biblioteca matemática (libm)

#include <math.h>
#include <stdio.h>

// Função de troca para o Quicksort e Heapsort
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função de particionamento para o Quicksort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Função do Quicksort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Função para manter a propriedade do Heap (para Heapsort)
void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

// Função do Heapsort
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

// Função do Insertion Sort (para subarrays pequenos)
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void introsortUtil(int arr[], int low, int high, int depthLimit) {
  int size = high - low + 1;
  if (size <= 16) { // Tamanho para mudar para Insertion Sort
    insertionSort(arr + low, size);
    return;
  }
  if (depthLimit == 0) {
    heapSort(arr + low, size);
    return;
  }
  int pivot = partition(arr, low, high);
  introsortUtil(arr, low, pivot - 1, depthLimit - 1);
  introsortUtil(arr, pivot + 1, high, depthLimit - 1);
}

// Função principal do intro sort
void introsort(int arr[], int n) {
  int depthLimit = 2 * log2(n); // Limite de profundidade para o Quicksort
  introsortUtil(arr, 0, n - 1, depthLimit);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {5, 2, 8, 1, 9, 0, 4, 7, 3, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array antes da ordenação: ");
  printArray(arr, n);

  introsort(arr, n);

  printf("Array depois da ordenação: ");
  printArray(arr, n);

  return 0;
}
