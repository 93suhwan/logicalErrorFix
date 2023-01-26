#include <bits/stdc++.h>
using namespace std;
const long long inf = 1100000000000000000;
long long mp[6] = {5, 3, 4, 1, 2, 0};
long long dp[61][6];
long long rec(long long k, long long col) {
  if (!k) return 0;
  if (k == 1) return 1;
  if (dp[k][col]) return dp[k][col];
  long long &res = dp[k][col];
  for (long long i = 0; i < 6; i++) {
    if (i == mp[col] || i == col) continue;
    res = (res + rec(k - 1, i)) % 1000000007;
  }
  res = (res * res) % 1000000007;
  return res;
}
void solve() {
  long long k;
  cin >> k;
  long long ans = 0;
  for (long long i = 0; i < 6; i++) ans = (ans + rec(k, i)) % 1000000007;
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long T = 1, cnt = 0;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
