#include <bits/stdc++.h>
using namespace std;
int n, a[55];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int fg = 0;
    for (int i = 1; i <= n; i++) {
      char c = getchar();
      while (c < '0' || c > '9') c = getchar();
      a[i] = c - '0';
      if (a[i] != 2 && a[i] != 3 && a[i] != 5 && a[i] != 7) fg = a[i];
    }
    if (fg) {
      printf("1\n%d\n", fg);
      continue;
    }
    puts("2");
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int x = a[i] * 10 + a[j];
        if (x != 23 && x != 37 && x != 53 && x != 73) {
          fg = x;
          break;
        }
      }
      if (fg) break;
    }
    printf("%d\n", fg);
  }
  return 0;
}
