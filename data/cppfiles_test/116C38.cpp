#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 1e6 + 10, inf = 1e9, mod = 998244353;
long long a[N + 2], dp[N + 2], dpSum[N + 2], dpRev[N + 2];
vector<long long> po[N + 2];
long long howMany(long long x, long long id) {
  if (x < 0) return 0;
  long long i = lower_bound(po[x].begin(), po[x].end(), id) - po[x].begin();
  return (long long)po[x].size() - i;
}
long long pw[N + 2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pw[0] = 1;
  for (long long i = 1; i <= N; i++) pw[i] = (pw[i - 1] * 2) % mod;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n + 4; i++) po[i].clear();
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      po[a[i]].push_back(i);
    }
    for (long long i = 0; i <= n + 4; i++) dp[i] = 0;
    for (long long i = 0; i <= n + 4; i++) dpSum[i] = 0;
    for (long long i = 0; i <= n + 4; i++) dpRev[i] = 0;
    for (long long i = 1; i <= n; i++) {
      if (a[i] == 0) {
        dp[i] = (dpSum[0] + 1) % mod;
        dpSum[0] = (dpSum[0] + dp[i]) % mod;
      } else {
        dp[i] = (dpSum[a[i]] + dpSum[a[i] - 1]) % mod;
        dpSum[a[i]] = (dpSum[a[i]] + dp[i]) % mod;
      }
    }
    long long ans = 0;
    for (long long i = n; i >= 1; i--) {
      long long num = howMany(a[i], i + 1) + howMany(a[i] - 2, i + 1);
      dpRev[a[i]] = (dpRev[a[i]] + pw[num]) % mod;
      ans = (ans + 1LL * dp[i] * (dpRev[a[i] + 2] + 1)) % mod;
    }
    ans = (ans + dpRev[1]) % mod;
    cout << ans << endl;
  }
  return 0;
}
