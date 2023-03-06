#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// counting digit sum of an integer
int digit_sum(int arg) {
  if (arg <= 0) { // check if argument is greater than 0
    return -1;
  }
  
  char buffer[50]; // length of integer
  sprintf(buffer, "%i", arg);
  int sum = 0; // sum counter
  for (int i = 0; i < 50; i++) {
    if (isdigit(buffer[i])) {
      sum += (int)buffer[i] - 48; // counting integer value of digit
    }
  }
  
  return sum;
}

// find max digit sum of randomly generated array
void max_digit_sum(int n) {
  srand(time(NULL)); // randomizing subsequent number generation
  
  int max_sum = 0, cur_sum = 0; // maximum sum and current sum respectively
  int *array = calloc(n, sizeof(int)); // creating an empty array

  for (int i = 0; i < n; i++) {
    array[i] = rand(); // generating an integer value
    printf("%i)\t%i\n", i + 1, array[i]);
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
}

// main function
int main() {
  printf("Enter a size of array: ");
  int n;
  if (!scanf("%i", &n)) {
    printf("Number must be integer");
  }
  
  if (n <= 0) {
    printf("Number must be natural");
    return -1;
  }

  max_digit_sum(n);
  return 0;
}