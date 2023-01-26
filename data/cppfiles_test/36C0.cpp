#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e5 + 100;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
int zs(int x) {
  int m = (int)sqrt(x + 0.5);
  for (int i = 2; i <= m; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int a[200];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    int p = 0;
    scanf("%d", &n);
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
      cnt += a[i] % 2;
      if (a[i] % 2) p = i;
    }
    if (cnt % 2 == 0) {
      printf("%d\n", n);
      for (int i = 1; i <= n; i++) {
        printf("%d ", i);
      }
      printf("\n");
    } else {
      if (zs(sum)) {
        printf("%d\n", n - 1);
        for (int i = 1; i <= n; i++) {
          if (i != p) {
            printf("%d ", i);
          }
        }
        printf("\n");
      } else {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
          printf("%d ", i);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
