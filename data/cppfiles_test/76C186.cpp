#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 5;
inline long long pow_mod(long long x, long long n, long long MOD = ::MOD) {
  n %= (MOD - 1);
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return res;
}
long long dp[N];
inline void solve() {
  int n, m;
  cin >> n >> m;
  long long prev = (dp[1] = 1);
  for (int i = 2; i <= n; i++) {
    dp[i] = prev;
    int t = sqrt(i);
    for (int j = 1; j <= t; j++) {
      if (j ^ 1 && j ^ (i / j)) dp[i] = (dp[i] + dp[i / j]) % m;
      dp[i] = (dp[i] + dp[j] * (i / j - i / (j + 1))) % m;
    }
    prev = (prev + dp[i]) % m;
  }
  cout << dp[n];
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
