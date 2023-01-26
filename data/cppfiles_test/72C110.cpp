#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
vector<int> lim;
i64 dp[13][1 << 10][2][11];
i64 solve(int p, int mask, int k, int s, int tight) {
  if (__builtin_popcount(mask) > k) return 0;
  if (p < 0) return 1;
  i64& res = dp[p][mask][s][k];
  if (tight && ~res) return res;
  i64 cnt = 0;
  for (int i = 0; i <= (tight ? 9 : lim[p]); i++) {
    if (!s && i == 0)
      cnt += solve(p - 1, 0, k, 0, 1);
    else
      cnt += solve(p - 1, mask | (1 << i), k, 1, tight | (i < lim[p]));
  }
  return (tight ? res = cnt : cnt);
}
i64 getSolve(i64 n, int k) {
  lim.clear();
  while (n) {
    lim.emplace_back(n % 10);
    n /= 10;
  }
  return solve((int)lim.size() - 1, 0, k, 0, 0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  memset(dp, -1, sizeof(dp));
  while (tt--) {
    int n, k;
    cin >> n >> k;
    i64 def = getSolve(n - 1, k);
    i64 lo = n, hi = 1e12;
    while (lo < hi) {
      const i64 mid = lo + (hi - lo) / 2;
      if (getSolve(mid, k) > def)
        hi = mid;
      else
        lo = mid + 1;
    }
    cout << hi << '\n';
  }
  return 0;
}
