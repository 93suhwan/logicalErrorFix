#include <bits/stdc++.h>
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1);
const double INF = 1e18;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, i, k, sum = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a + 1, a + n + 1);
    long long tot = 0, ans = 1e18;
    for (i = n; i >= 1; i--) {
      long long w = max(0LL, sum - tot - k);
      ans = min(ans, n - i + (w + n - i) / (n - i + 1));
      tot += a[i] - a[1];
    }
    cout << ans << endl;
  }
  return 0;
}
