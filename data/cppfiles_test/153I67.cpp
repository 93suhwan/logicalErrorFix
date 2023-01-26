#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = (1 << 23) + 1, mod = 998244353;
int t, n, dp[M][27];
string second[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> second[i];
  }
  for (int j = 0; j <= 25; j++) {
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (int k = 0; k < second[i].size(); k++) {
        c += (second[i][k] - 'a' == j);
      }
      v.push_back({c, i});
    }
    sort(v.rbegin(), v.rend());
    int p = 0;
    for (int k = 0; k < v.size(); k++) {
      for (int m = p;; m = (m - 1) & p) {
        dp[m ^ (1 << v[k].second)][j] = v[k].first;
        if (!m) break;
      }
      p += 1 << v[k].second;
    }
  }
  long long ans = 0;
  for (int mask = 1; mask < (1 << n); mask++) {
    int c = __builtin_popcount(mask);
    vector<int> mn(27);
    for (int i = 0; i <= 25; i++) mn[i] = dp[mask][i], dp[mask][i] = 0;
    dp[mask][0] = (c % 2 ? 1 : -1);
    for (int i = 0; i <= 25; i++)
      dp[mask][0] = (long long)dp[mask][0] * (mn[i] + 1) % mod;
    dp[mask][0] += (c % 2 ? -1 : 1);
    dp[mask][0] %= mod;
    int ids = 0;
    for (int i = 0; i < n; i++) {
      if (i) dp[mask][i] += dp[mask][i - 1];
      dp[mask][i] %= mod;
      if (mask & (1 << i)) {
        dp[mask][i] += (dp[mask ^ (1 << i)][i] + mod) % mod;
        ids += i + 1;
      }
      dp[mask][i] %= mod;
    }
    ans ^= (long long)c * ids * ((dp[mask][n - 1] + 1) % mod);
  }
  cout << ans << endl;
}
