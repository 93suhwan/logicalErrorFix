#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int power[24] = {0};
const int mod = 998244353;
int sgn(int x) { return (x % 2 ? 1 : -1); }
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n);
  for (int z = 0; z < n; z++) {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    v[z] = cnt;
  }
  vector<int> f(power[n], 0);
  vector<vector<int>> dp(power[n], vector<int>(n, 0));
  vector<vector<int>> cnt(power[n], vector<int>(26, 0));
  vector<int> popcnt(power[n], 0);
  for (int z = 0; z < 26; z++) cnt[0][z] = INF;
  for (int mask = 1; mask < power[n]; mask++) {
    for (int z = 0; z < n; z++) {
      if (power[z] & mask) {
        for (int i = 0; i < 26; i++) {
          cnt[mask][i] = min(v[z][i], cnt[mask ^ power[z]][i]);
        }
        popcnt[mask] = popcnt[mask ^ power[z]] + 1;
        break;
      }
    }
    long long int val = 1;
    for (int i = 0; i < 26; i++) {
      val *= (long long int)(cnt[mask][i] + 1);
      if (val >= mod) val %= mod;
    }
    dp[mask][0] = val;
    if (dp[mask][0] >= mod) dp[mask][0] %= mod;
    if (power[0] & mask) {
      dp[mask][0] += dp[mask ^ power[0]][0];
      if (dp[mask][0] >= mod) dp[mask][0] %= mod;
    }
    for (int i = 1; i < n; i++) {
      dp[mask][i] = dp[mask][i - 1];
      if (mask & power[i]) {
        dp[mask][i] += dp[mask ^ power[i]][i - 1];
        if (dp[mask][i] >= mod) dp[mask][i] %= mod;
      }
    }
    f[mask] = dp[mask][n - 1];
  }
  long long int res = 0;
  for (int mask = 1; mask < power[n]; mask++) {
    long long int c = popcnt[mask];
    {
      int sum = 0;
      for (int z = 0; z < n; z++) {
        if (power[z] & mask) {
          sum += z + 1;
        }
      }
      c *= sum;
    }
    c *= (long long int)f[mask];
    res ^= c;
  }
  cout << res << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  power[0] = 1;
  for (int j = 1; j <= 30; j++) power[j] = power[j - 1] * 2;
  while (t--) {
    solve();
  }
  return 0;
}
