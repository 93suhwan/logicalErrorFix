#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long a[N];
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    long long ans = -4e18;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < min(200, i); ++j) {
        ans = max(ans, (long long)i * j - (long long)k * (a[i] | a[j]));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
