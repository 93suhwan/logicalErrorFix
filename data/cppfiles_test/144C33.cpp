#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    if (n % m == 0) {
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
          printf("%d", n / m);
          for (int k = 0; k < n / m; ++k) {
            printf(" %d", j * (n / m) + k + 1);
          }
          puts("");
        }
      }
    } else {
      int lb = 0;
      for (int i = 0; i < k; ++i) {
        int se = -1;
        for (int j = 0; j < m; ++j) {
          int v = (n / m) + (j < n % m);
          printf("%d", v);
          for (int k = 0; k < v; ++k) {
            if (k == 0 && j == (n % m)) se = lb;
            printf(" %d", lb + 1);
            lb = (lb + 1) % n;
          }
          puts("");
        }
        lb = se;
      }
    }
    puts("");
  }
  return 0;
}
