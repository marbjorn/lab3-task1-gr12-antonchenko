#include <stdio.h>
#include <ctype.h>

int digit_sum(float arg) {
  if (arg <= 0) {
    return -1;
  } 
  char buffer[50]; //size of the number
  sprintf(buffer, "%f", arg);
  int sum = 0;
  for (int i = 0; i < 50; i++) {
    if (isdigit(buffer[i])) {
      sum += (int)buffer[i] - 48;
    }
  }
  return sum;
}


int main() {
  printf("%i", digit_sum(1.123));
  return 0;
}