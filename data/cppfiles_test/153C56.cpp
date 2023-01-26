#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename A, typename B>
bool ckmin(A& a, B b) {
  return a > b ? a = b, true : false;
}
const int inf = 1e9 + 69;
const int MOD = 998244353;
inline void add(int& a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
int n;
int cnt[30][26];
int dp[(1 << 23) + 5];
int f[(1 << 23) + 5];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    42;
    for (auto ch : s) ++cnt[i][ch - 'a'];
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (mask == 0) continue;
    dp[mask] = 1;
    for (int i = 0; i < 26; ++i) {
      int mn = inf;
      for (int j = 0; j < n; ++j)
        if (mask >> j & 1) {
          mn = min(mn, cnt[j][i]);
        }
      42;
      assert(mn != inf);
      dp[mask] = (ll)dp[mask] * (mn + 1) % MOD;
    }
    int u = __builtin_popcount(mask);
    42;
    if (u % 2 == 0) dp[mask] = MOD - dp[mask];
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask >> i & 1) {
        f[mask] += i + 1;
        assert(mask != 0);
        continue;
      }
      add(dp[mask | (1 << i)], dp[mask]);
      42;
    }
  }
  ll res = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (mask == 0) continue;
    int u = __builtin_popcount(mask);
    42;
    res ^= (ll)dp[mask] * u * f[mask];
  }
  cout << res;
  return 0;
}
