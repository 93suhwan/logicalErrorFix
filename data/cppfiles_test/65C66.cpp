#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> l(n), r(n);
  for (long long i = 0; i < n; i++) cin >> l[i] >> r[i];
  vector<long long> result(m + 1);
  for (long long g = 1; g <= m; g++) {
    long long to = m / g;
    vector<long long> dp(to + 1, 1);
    for (long long i = 0; i < n; i++) {
      long long mn = (l[i] + g - 1) / g;
      long long mx = r[i] / g;
      if (mx < mn) {
        dp[to] = 0;
        break;
      }
      vector<long long> ndp(to + 1);
      for (long long s = mn; s <= to; s++) {
        ndp[s] =
            (ndp[s - 1] + dp[s - mn] - (s - mx - 1 >= 0 ? dp[s - mx - 1] : 0)) %
            MOD;
        if (ndp[s] < 0) ndp[s] += MOD;
      }
      dp = ndp;
    }
    result[g] = dp[to];
  }
  for (long long g = m; g; g--) {
    for (long long i = 2 * g; i <= m; i += g) {
      result[g] -= result[i];
      if (result[g] < 0) result[g] += MOD;
    }
  }
  cout << result[1];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
