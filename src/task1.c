#include <stdio.h>
#include <stdlib.h>

int digit_sum(int arg) {
  if (arg <= 0) {
    return -1;
  } 
  char buffer[50]; //size of the number
  sprintf(buffer, "%i", arg);
  int sum = 0;
  for (int i = 0; i < 50; i++) {
    if (isdigit(buffer[i])) {
      sum += (int)buffer[i] - 48;
    }
  }
  return sum;
}


int main() {
  int n;
  int max_sum = 0, cur_sum = 0;
  
  printf("Enter a size of array: ");
  scanf("%i", &n);
  int* array = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("%i) ", i+1);
    scanf("%i", &array[i]);
    cur_sum = digit_sum(array[i]);
    if (cur_sum >= max_sum) {
      max_sum = cur_sum;
    }
  }
  printf("Max digit sum of elements: %i\n", max_sum);
  printf("Output number(s): ");
  for (int i = 0; i < n; i++) {
    if (max_sum == digit_sum(array[i])) {
      printf("%i\t", array[i]);
    }
  }
  
  free(array);
  return 0;
}