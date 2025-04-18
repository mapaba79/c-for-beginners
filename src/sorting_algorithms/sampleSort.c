#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

// Versão simplificada: divide o array em k blocos, ordena, junta
void sampleSort(int arr[], int n, int k) {
  int blockSize = n / k;
  int start, end;

  // Ordena blocos menores
  for (int i = 0; i < k; i++) {
    start = i * blockSize;
    end = (i == k - 1) ? n : start + blockSize;
    qsort(&arr[start], end - start, sizeof(int), compare);
  }

  // Junta tudo ordenando novamente (simplificação)
  qsort(arr, n, sizeof(int), compare);
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n, k;

  printf("Quantos números você quer ordenar? ");
  scanf("%d", &n);

  int *arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  printf("Digite os %d números:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Em quantos blocos deseja dividir para o Sample Sort? ");
  scanf("%d", &k);

  // Validação básica
  if (k < 1 || k > n) {
    printf("Número inválido de blocos. Deve estar entre 1 e %d.\n", n);
    free(arr);
    return 1;
  }

  printf("\nArray original:\n");
  printArray(arr, n);

  sampleSort(arr, n, k);

  printf("Array ordenado com Sample Sort:\n");
  printArray(arr, n);

  free(arr);
  return 0;
}
