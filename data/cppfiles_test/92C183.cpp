#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    char str1[101];
    scanf("%s", str1);
    int count = 0;
    for (int j = 0; j < strlen(str1) - 1; j++) {
      if (str1[j] == 'a' && str1[j + 1] == 'b') {
        count += 1;
      } else if (str1[j] == 'b' && str1[j + 1] == 'a') {
        count -= 1;
      }
    }
    if (count == 0) {
      printf("%s\n", str1);
    } else if (count == 1) {
      for (int j = 0; j < strlen(str1) - 1; j++) {
        printf("%c", str1[j]);
      }
      printf("a\n");
    } else {
      for (int j = 0; j < strlen(str1) - 1; j++) {
        printf("%c", str1[j]);
      }
      printf("b\n");
    }
  }
  return 0;
}
