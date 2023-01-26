#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 2222 + 100, inf = 1e18 + 1, mod = 1e9 + 7, sqrtN = 333;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, sum, x, y, z, w, base, ans;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
ll dp[n_][n_][2], A[n_][n_];
void solve() {
  ll q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) A[i][j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = A[i][j] * (dp[i][j - 1][1] + A[i][j - 1]);
      dp[i][j][1] = A[i][j] * (dp[i - 1][j][0] + A[i - 1][j]);
      ans += dp[i][j][0] + dp[i][j][1] + A[i][j];
    }
  ll i, j;
  while (q--) {
    cin >> i >> j;
    ans -= dp[i][j][0] + dp[i][j][1] + A[i][j];
    A[i][j] ^= 1;
    dp[i][j][0] = A[i][j] * (dp[i][j - 1][1] + A[i][j - 1]);
    dp[i][j][1] = A[i][j] * (dp[i - 1][j][0] + A[i - 1][j]);
    ans += dp[i][j][0] + dp[i][j][1] + A[i][j];
    b = i + 1, a = j, c = 0;
    while (1) {
      if (b > n || a > m) break;
      ans -= dp[b][a][0] + dp[b][a][1] + A[b][a];
      dp[b][a][0] = A[b][a] * (dp[b][a - 1][1] + A[b][a - 1]);
      dp[b][a][1] = A[b][a] * (dp[b - 1][a][0] + A[b - 1][a]);
      ans += dp[b][a][0] + dp[b][a][1] + A[b][a];
      if (c)
        b++;
      else
        a++;
      c = (c + 1) % 2;
    }
    b = i, a = j + 1, c = 1;
    while (1) {
      if (b > n || a > m) break;
      ans -= dp[b][a][0] + dp[b][a][1] + A[b][a];
      dp[b][a][0] = A[b][a] * (dp[b][a - 1][1] + A[b][a - 1]);
      dp[b][a][1] = A[b][a] * (dp[b - 1][a][0] + A[b - 1][a]);
      ans += dp[b][a][0] + dp[b][a][1] + A[b][a];
      if (c)
        b++;
      else
        a++;
      c = (c + 1) % 2;
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  while (tc--) solve();
}
