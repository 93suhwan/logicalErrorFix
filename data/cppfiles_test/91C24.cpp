#include <bits/stdc++.h>
using namespace std;
constexpr int Max = 1e5 + 100;
constexpr long long mod = 998244353;
int n, a[Max], f[2][Max];
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long ans = 0;
  vector<int> val[2];
  for (int i = n; i >= 1; --i) {
    int last = a[i];
    const int s = i & 1;
    val[s].emplace_back(a[i]);
    f[s][a[i]] = 1;
    for (int j : val[s ^ 1]) {
      const int x = f[s ^ 1][j];
      const int k = (a[i] + j - 1) / j;
      const int st = a[i] / k;
      ans = (ans + 1ll * (k - 1) * x % mod * i % mod) % mod;
      f[s][st] = (f[s][st] + x) % mod;
      if (last != st) val[s].emplace_back(st), last = st;
    }
    for (int x : val[s ^ 1]) f[s ^ 1][x] = 0;
    val[s ^ 1].clear();
  }
  for (int i : val[0]) f[0][i] = 0;
  for (int i : val[1]) f[1][i] = 0;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int Case;
  cin >> Case;
  while (Case--) solve();
  return 0;
}
