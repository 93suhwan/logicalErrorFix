#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1000][1000];
ll st[2000];
ll ist[2000];
const ll mod = 998244353;
ll choose(ll a, ll j) {
  if (j == 0 || j == a) return 1;
  return st[a] * ist[j] % mod * ist[a - j] % mod;
}
ll mpow(ll a, ll j) {
  if (j == 0) return 1;
  ll now = mpow(a, j / 2);
  now = now * now % mod;
  if (j % 2) now = now * a % mod;
  return now;
}
ll inv(ll i) { return mpow(i, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  st[0] = 1;
  for (int i = 1; i < 2000; ++i) st[i] = st[i - 1] * i % mod;
  for (int i = 1; i < 2000; ++i) ist[i] = inv(i);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i < x + n; ++i) dp[0][i] = 1;
  int sx = x;
  x--;
  while (x >= 0) {
    for (int a = 2; a <= n; ++a) {
      for (int j = 0; j <= a; ++j) {
        dp[a][x] += dp[a - j][x + a - 1] * choose(a, j) % mod *
                    mpow(min(a - 1, sx - x), j) % mod;
        dp[a][x] %= mod;
      }
    }
    x--;
  }
  cout << dp[n][0] << endl;
}
