#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, cnt[200003];
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    int CNT = 0;
    for (int i = 0; i < n; i++) cnt[i] = n / m;
    for (int i = 0; i < n % m; i++) cnt[i]++, CNT += cnt[i];
    for (int i = 0; i < k; i++) {
      int nw = CNT * i % n;
      for (int j = 0; j < m; j++) {
        printf("%d ", cnt[j]);
        for (int k = 0; k < cnt[j]; k++) {
          printf("%d ", nw + 1);
          nw++;
          if (nw == n) nw = 0;
        }
        printf("\n");
      }
    }
  }
}
