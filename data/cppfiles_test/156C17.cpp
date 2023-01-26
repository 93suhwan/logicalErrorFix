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
    if (n == 1) ans = jian;
    for (long long i = 1; i < n; i++) {
      ans = min(ans, jian);
      long long now = (pre[i] + a[n] - jian) / (i + 1);
      if ((pre[i] + a[n] - jian) < 0) {
        now = (pre[i] + a[n] - jian - i) / (i + 1);
      }
      if (now >= a[n]) {
        ans = min(ans, i);
      } else {
        ans = min(ans, i + a[n] - now);
      }
    }
    cout << ans << endl;
  }
}
