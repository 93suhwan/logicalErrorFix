#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 10;
const long long mod = 1000000007;
void solve() {
  long long n, mod;
  cin >> n >> mod;
  vector<long long> dp(n + 1), pref(n + 1);
  dp[1] = 1;
  pref[1] = 1;
  for (long long i = 2; i < n + 1; i++) {
    long long z = sqrt(i);
    long long last = i - 1;
    for (long long j = 2; j < z + 1; j++) {
      long long id = i / j;
      long long f = (pref[last] - pref[id] + mod) % mod;
      long long g = (dp[id] * 2) % mod;
      dp[i] = (dp[i] + (f + g) % mod) % mod;
      last = id - 1;
    }
    last = z;
    for (long long j = (i / z) - 1; j >= 1; j--) {
      long long id = i / j;
      long long f = ((id - last + 1) * dp[j]) % mod;
      dp[i] = (dp[i] + f) % mod;
      last = id;
    }
    pref[i] = (pref[i - 1] + dp[i]) % mod;
  }
  cout << dp[n] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
