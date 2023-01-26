#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    int cnt1 = n % m;
    int cnt2 = m - cnt1;
    int t = 1;
    while (k--) {
      for (int i = 1; i <= cnt2; i++) {
        printf("%d ", n / m);
        for (int j = 1; j <= n / m; j++) {
          printf("%d ", t);
          t++;
          if (t > n) t = 1;
        }
        puts("");
      }
      int tmp = t;
      for (int i = 1; i <= cnt1; i++) {
        printf("%d ", n / m + 1);
        for (int j = 1; j <= n / m + 1; j++) {
          printf("%d ", t);
          t++;
          if (t > n) t = 1;
        }
        puts("");
      }
      t = tmp;
    }
    puts("");
  }
  return 0;
}
