#include <bits/stdc++.h>
using namespace std;
long long a[200005], pre[200005];
bool cmp(long long a, long long b) { return a > b; }
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    for (long long i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    if (pre[n] <= k) {
      cout << 0 << endl;
      continue;
    }
    long long jian = pre[n] - k;
    long long ans = 999999999999;
    for (long long i = 1; i <= n; i++) {
      long long now = (pre[i] - jian) / i;
      if (now >= a[n]) {
        ans = min(ans, i);
      } else {
        ans = min(ans, i + a[n] - now);
        if (i == n) ans = min(ans, i + a[n] - now - 1);
      }
    }
    cout << ans << endl;
  }
}
