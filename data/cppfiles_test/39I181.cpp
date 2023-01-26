#include <bits/stdc++.h>
using namespace std;
int n, d[110], a1, maxx;
int main() {
  scanf("%d", &n);
  for (int c = 2; c <= n; c++) {
    printf("? 1 ");
    for (int j = 1; j <= n - 1; j++) printf("%d ", c);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 0) {
      a1 = n + 2 - c;
      break;
    }
    d[x] = c - 1;
  }
  for (int c = 2; c <= n; c++) {
    printf("? %d ", c);
    for (int j = 1; j <= n - 1; j++) printf("%d ", 1);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == 0) break;
    d[x] = -(c - 1);
  }
  printf("! %d ", a1);
  for (int i = 2; i <= n; i++) {
    printf("%d ", a1 + d[i]);
  }
}
