#include <stdio.h>

void gnomeSort(int arr[], int n) {
  int index = 0;
  while (index < n) {
    if (index == 0)
      index++;
    if (arr[index] >= arr[index - 1])
      index++;
    else {
      int temp = arr[index];
      arr[index] = arr[index - 1];
      arr[index - 1] = temp;
      index--;
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

  printf("How many numbers do you want to sort? ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(arr, n);

  gnomeSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
