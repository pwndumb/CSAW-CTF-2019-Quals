#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[] = {
    119, 102, 123, 95, 110, 121, 125, -1, 98, 108, 114, -1, -1,  -1, -1, -1, -1,
    97,  101, 105, -1, 111, 116, -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  103, -1,  -1, -1, -1,  -1,  -1, 117, -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1,  -1, -1,  -1, -1, -1, -1,
    -1,  -1,  -1,  -1, -1,  -1,  -1,  -1, -1, -1,  -1};

size_t fleg[] = {1, 9, 17, 39, 2,  0, 18, 3,  8, 18, 9,  18, 17, 1,  3,  19, 4,
                 3, 5, 21, 46, 10, 3, 10, 18, 3, 1,  46, 22, 46, 10, 18, 6};

size_t find(char value) {
  size_t level = 0;

  while (level != -1) {
    if (value == arr[level]) {
      return level;
    } else if (value < arr[level]) {
      level = 2 * level + 1;
    } else if (value > arr[level]) {
      level = 2 * level + 2;
    }
  }
  return level;
}

int main(int argc, char *argv[]) {
  printf("Enter the flag\n>>> ");
  char buf[128];
  scanf("%s", buf);
  size_t buf_len = strlen(buf);

  if (buf_len < sizeof(fleg) / sizeof(fleg[0])) {
    printf("Incorrect!\n");
    exit(1);
  }

  for (size_t i = 0; i < buf_len; i++) {
    size_t index = find(buf[i]);
    if (fleg[i] != index) {
      printf("Incorrect!\n");
      exit(1);
    }
  }
  printf("Correct!\n");
  return 0;
}