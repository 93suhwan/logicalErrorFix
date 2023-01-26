#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
ll A[1010][1010];
ll dp[1010][1010], dp1[1010][1010], dp2[1010][1010];
ll res = 0;
void f(ll i, ll j) {
  if (A[i][j] == 1) {
    return;
  }
  dp[i][j] = dp1[i][j - 1] + dp2[i - 1][j] + 1;
  dp1[i][j] = dp2[i - 1][j] + 1;
  dp2[i][j] = dp1[i][j - 1] + 1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, Q;
  cin >> n >> m >> Q;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      f(i, j);
      res += dp[i][j];
    }
  }
  while (Q--) {
    ll x, y;
    cin >> x >> y;
    A[x][y] ^= 1;
    if (A[x][y] == 1) {
      res -= dp[x][y];
      dp[x][y] = dp1[x][y] = dp2[x][y] = 0;
      if (x < n) {
        res -= dp[x + 1][y];
        f(x + 1, y);
        res += dp[x + 1][y];
      }
      if (y < m) {
        res -= dp[x][y + 1];
        f(x, y + 1);
        res += dp[x][y + 1];
      }
      ++x, ++y;
      while (x <= n && y <= m) {
        res -= dp[x][y];
        f(x, y);
        res += dp[x][y];
        if (x < n) {
          res -= dp[x + 1][y];
          f(x + 1, y);
          res += dp[x + 1][y];
        }
        if (y < m) {
          res -= dp[x][y + 1];
          f(x, y + 1);
          res += dp[x][y + 1];
        }
        ++x, ++y;
      }
    } else {
      while (x <= n && y <= m) {
        res -= dp[x][y];
        f(x, y);
        res += dp[x][y];
        if (x < n) {
          res -= dp[x + 1][y];
          f(x + 1, y);
          res += dp[x + 1][y];
        }
        if (y < m) {
          res -= dp[x][y + 1];
          f(x, y + 1);
          res += dp[x][y + 1];
        }
        ++x, ++y;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
