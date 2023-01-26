#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e9;
const int MAXN = 2e5 + 2;
const int oo = 1e9;
const long long oo15 = 1e15;
const long long oo18 = 1e18 + 3;
const long long oooo = 9223372036854775807;
long long dp[2][100005];
int a[100005];
vector<int> ldk[2];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  ldk[n % 2].push_back(a[n]);
  dp[n % 2][a[n]] = 1;
  for (int i = n - 1; i; i--) {
    ldk[i % 2].push_back(a[i]);
    dp[i % 2][a[i]] = 1;
    for (auto v : ldk[1 - i % 2]) {
      int k = (a[i] + v - 1) / v;
      res += 1ll * (k - 1) * i % MOD1 * dp[1 - i % 2][v] % MOD1;
      res %= MOD1;
      dp[i % 2][a[i] / k] += dp[1 - i % 2][v];
      dp[i % 2][a[i] / k] %= MOD1;
      if (ldk[i % 2].empty() || ldk[i % 2].back() != a[i] / k)
        ldk[i % 2].push_back(a[i] / k);
    }
    for (auto v : ldk[1 - i % 2]) dp[1 - i % 2][v] = 0;
    ldk[1 - i % 2].clear();
  }
  for (auto v : ldk[1]) dp[1][v] = 0;
  ldk[1].clear();
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  cin >> testcase;
  while (testcase--) solve();
}
