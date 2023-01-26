#include <bits/stdc++.h>
using namespace std;
long long pre[200005][20];
int32_t main() {
  for (long long i = 1; i <= 200000; i++) {
    for (long long j = 0; j < 20; j++) {
      pre[i][j] = pre[i - 1][j];
      if ((i & (1 << j))) {
        ++pre[i][j];
      }
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    for (long long i = 0; i < 20; i++) {
      ans = max(ans, pre[r][i] - pre[l - 1][i]);
    }
    cout << r - l + 1 - ans << '\n';
  }
}
