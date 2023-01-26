#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 5e2 + 12;
const long long Mod = 998244353;
const long long oo = 1e18;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
long long n, x, ans = 0;
long long gt[N], dao[N];
long long f[N][N], g[N][N];
long long Pow(long long a, long long b) {
  if (a <= 0) return 0;
  if (b == 0) return 1;
  long long tmp = Pow(a, b / 2) % Mod;
  tmp = tmp * tmp % Mod;
  if (b % 2) return tmp * a % Mod;
  return tmp;
}
long long C(int k, int n) {
  if (k > n) return 1;
  long long ret = dao[k] * dao[n - k] % Mod;
  ret = ret * gt[n] % Mod;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x;
  gt[0] = 1;
  for (int _ = 1, __ = n, i = _; i <= __; i++) gt[i] = gt[i - 1] * i % Mod;
  dao[n] = Pow(gt[n], Mod - 2);
  for (int _ = n - 1, __ = 0, i = _; i >= __; i--)
    dao[i] = dao[i + 1] * (i + 1) % Mod;
  for (int _ = 2, __ = n, i = _; i <= __; i++)
    for (int _ = 0, __ = i - 1, k = _; k <= __; k++)
      g[i][k] = Pow(i - 1, k) * C(k, i) % Mod;
  for (int _ = x, __ = 1, i = _; i >= __; i--) f[1][i] = 1;
  for (int _ = 2, __ = n, i = _; i <= __; i++)
    for (int _ = i, __ = x, j = _; j <= __; j++)
      for (int _ = 0, __ = i - 1, k = _; k <= __; k++) {
        f[i][j] = (f[i][j] + f[i - k][j - i + 1] * g[i][k] % Mod) % Mod;
      }
  long long ans = 0;
  for (int _ = x, __ = 1, i = _; i >= __; i--)
    ans = (ans - f[n][i] + Mod * Mod) % Mod;
  ans = (ans + Pow(x, n)) % Mod;
  cout << ans;
}
