#include <stdio.h>

int main(){
  int n, sum = 0;
  
  // Ask for user input
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Calculate sum of even numbers
  for (int i = 2; i <= n; i += 2) {
    sum += i;
  }

  // Print the sum
  printf("Sum of even numbers from 2 to %d is %d\n", n, sum);

  return 0;
}
