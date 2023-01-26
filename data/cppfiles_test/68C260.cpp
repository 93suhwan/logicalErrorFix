#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int kk = sqrt(k);
    int ans = kk * kk;
    if (kk * kk == k) {
      printf("%d 1\n", kk);
    } else {
      kk++;
      if (k <= ans + kk) {
        printf("%d %d\n", k - ans, kk);
      } else
        printf("%d %d\n", kk, kk - (k - ans - kk));
    }
  }
}
