#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common/parsing.h"

int main(void) {
  char (*arr)[C] = allocate_lines();
  int i, j, len, tmp, *num_arr, retval = 0, n = get_lines(arr), k = 0;

  /* @@ PART 1 @@ */

  for (i = 0; i < n; i++) {
    // parse array of integers
    num_arr = number_arr(arr[i]);
    if (num_arr == NULL) { continue; }
    len = num_arr[0];
    // downward propagate
    for (;;) {
      tmp = 0;
      for (j = 1; j < len; j++) {
        tmp += num_arr[j];
      }
      if (!tmp) { break; }
      len--;
      for (j = 1; j < len; j++) {
        num_arr[j] = num_arr[j+1] - num_arr[j];
      }
    }
    // upward propagate
    tmp = num_arr[0];
    while (j < tmp) {
      retval += num_arr[j++];
    }
    free(num_arr);
  }
  printf("part 1: %d\n", retval);

  /* @@ PART 2 @@ */
  
  get_lines(arr);
  retval = 0;
  for (i = 0; i < n; i++) {
    // parse array of integers
    num_arr = number_arr(arr[i]);
    if (num_arr == NULL) { continue; }
    len = num_arr[0];
    // downward propagate
    for (;;) {
      tmp = 0;
      for (j = k; j < len; j++) {
        tmp += num_arr[j];
      }
      if (!tmp) { break; }
      k++;
      for (j = len-1; j > k; j--) {
        num_arr[j] = num_arr[j] - num_arr[j-1];
      }
    }
    // upward propagate
    tmp = 0;
    while (--k > 0) {
      tmp = num_arr[k] - tmp;
    }
    retval += tmp;
    free(num_arr);
  }
  printf("part 2: %d\n", retval);

  free(arr);
  return 0;
}
