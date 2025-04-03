#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore de busca binária
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Função para criar um novo nó
Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

// Função para inserir um nó na BST
Node *insert(Node *node, int data) {
  if (node == NULL)
    return newNode(data);
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);
  return node;
}

// Função para realizar a travessia in-order e armazenar os elements ordenados
void inOrderTraversal(Node *node, int arr[], int *index) {
  if (node != NULL) {
    inOrderTraversal(node->left, arr, index);
    arr[(*index)++] = node->data;
    inOrderTraversal(node->right, arr, index);
  }
}

// Função principal do Tree Sort
void treeSort(int arr[], int n) {
  Node *root = NULL;
  for (int i = 0; i < n; i++) {
    root = insert(root, arr[i]);
  }

  int index = 0;
  inOrderTraversal(root, arr, &index);
}

// Função para imprimir um array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {5, 8, 1, 9, 3, 7, 2, 4, 0, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array original: ");
  printArray(arr, n);

  treeSort(arr, n);

  printf("Array ordenado: ");
  printArray(arr, n);

  return 0;
}
