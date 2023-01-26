#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (n <= 26) {
      for (i = 0; i < n; i++) {
        printf("%c", 'a' + i);
      }
    } else if (n % 2 == 0) {
      for (i = 0; i < n / 2; i++) {
        printf("a");
      }
      printf("b");
      for (i = 0; i < n / 2 - 1; i++) {
        printf("a");
      }
    } else {
      for (i = 0; i < n / 2; i++) {
        printf("a");
      }
      printf("bc");
      for (i = 0; i < n / 2 - 1; i++) {
        printf("a");
      }
    }
    printf("\n");
  }
  return 0;
}
