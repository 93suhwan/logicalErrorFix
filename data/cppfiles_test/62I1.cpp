#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long poww(long long a, long long b, long long mod) {
  long long res = 1;
  if (b < 0 || b >= Mod) b = (b % (mod - 1) + mod - 1) % (mod - 1);
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
void Max(long long& x, long long y) { x = max(x, y); }
void Min(long long& x, long long y) { x = min(x, y); }
void OK(bool yes) { cout << (yes ? "YES\n" : "NO\n"); }
const long long N = 500300, M = 2010, LN = (1 << 24), K = 17, inf = 3e18,
                Mod1 = 1e9 + 7, Mod2 = 999997457;
const long double pi = acos(-1), eps = 1e-12;
long long Fact[N], iFact[N];
void init() {
  Fact[0] = iFact[0] = 1ll;
  for (long long i = 1; i < N; i++) Fact[i] = (1ll * Fact[i - 1] * i) % Mod;
  iFact[N - 1] = poww(Fact[N - 1], -1, Mod);
  for (long long i = N - 2; i; i--)
    iFact[i] = (1ll * iFact[i + 1] * (i + 1)) % Mod;
}
long long Cnk(long long x, long long y) {
  if (y > x) return 0;
  return (((Fact[x] * poww(Fact[y], -1, Mod)) % Mod) *
          poww(Fact[x - y], -1, Mod)) %
         Mod;
}
void Add(long long& x, long long y, long long j = 0) {
  long long mod = Mod;
  if (j == 1) mod = Mod1;
  if (j == 2) mod = Mod2;
  x %= mod;
  y %= mod;
  if (x < 0) x += mod;
  if (y < 0) y += mod;
  x = (x + y >= mod ? x + y - mod : x + y);
}
bool ok = 1;
long long a[N], b[N];
int rg = 0, bt = 1, both = 2;
long long dp[1010][1010][3];
long long memo[1010][1010][3];
long long vis[1010][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long T = 1;
  long long Case = 1;
  while (T--) {
    long long n, m, q, Sum = 0;
    cin >> n >> m >> q;
    for (int i = n; i; i--) {
      for (int j = m; j; j--) {
        memo[i][j][rg] = dp[i][j][rg] = (j < m) + dp[i][j + 1][bt];
        memo[i][j][bt] = dp[i][j][bt] = (i < n) + dp[i + 1][j][rg];
        memo[i][j][both] = dp[i][j][both] = dp[i][j][rg] + dp[i][j][bt] + 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        Sum += dp[i][j][both];
      }
    }
    long long Ans = Sum;
    while (q--) {
      long long x, y;
      cin >> x >> y;
      vis[x][y] ^= 1;
      if (vis[x][y]) {
        Ans -= dp[x][y][both];
        long long x1 = x, y1 = y - 1;
        while (x1 > 0 && y1 > 0) {
          if ((!vis[x1][y1]) && (!(vis[x1][y1 + 1] && y1 + 1 != y))) {
            dp[x1][y1][rg] -= 1 + dp[x][y][bt];
            dp[x1][y1][both] -= 1 + dp[x][y][bt];
            Ans -= 1 + dp[x][y][bt];
          } else
            break;
          x1--;
          y1--;
        }
        x1 = x - 1, y1 = y;
        while (x1 > 0 && y1 > 0) {
          if ((!vis[x1][y1]) && (!(vis[x1 + 1][y1] && x1 + 1 != x))) {
            dp[x1][y1][bt] -= 1 + dp[x][y][rg];
            dp[x1][y1][both] -= 1 + dp[x][y][rg];
            Ans -= 1 + dp[x][y][rg];
          } else
            break;
          x1--;
          y1--;
        }
        x1 = x - 1, y1 = y - 1;
        while (x1 > 0 && y1 > 0) {
          if (!vis[x1][y1]) {
            if (!vis[x1 + 1][y1]) {
              Ans -= 1 + dp[x][y][bt];
              dp[x1][y1][bt] -= dp[x][y][both];
              dp[x1][y1][both] -= dp[x][y][both];
            }
            if (!vis[x1][y1 + 1]) {
              Ans -= 1 + dp[x][y][rg];
              dp[x1][y1][rg] -= dp[x][y][both];
              dp[x1][y1][both] -= dp[x][y][both];
            }
            if (vis[x1][y1 + 1] && vis[x1 + 1][y1]) break;
          } else
            break;
          x1--;
          y1--;
        }
        dp[x][y][rg] = dp[x][y][bt] = dp[x][y][both] = 0;
      } else {
        dp[x][y][rg] = (y < m) * (!vis[x][y + 1]) + dp[x][y + 1][bt];
        dp[x][y][bt] = (x < n) * (!vis[x + 1][y]) + dp[x + 1][y][rg];
        dp[x][y][both] = dp[x][y][rg] + dp[x][y][bt] + 1;
        Ans += dp[x][y][both];
        long long x1 = x, y1 = y - 1;
        while (x1 > 0 && y1 > 0) {
          if ((!vis[x1][y1]) && (!(vis[x1][y1 + 1] && y1 + 1 != y))) {
            dp[x1][y1][rg] += 1 + dp[x][y][bt];
            dp[x1][y1][both] += 1 + dp[x][y][bt];
            Ans += 1 + dp[x][y][bt];
          } else
            break;
          x1--;
          y1--;
        }
        x1 = x - 1, y1 = y;
        while (x1 > 0 && y1 > 0) {
          if ((!vis[x1][y1]) && (!(vis[x1 + 1][y1] && x1 + 1 != x))) {
            dp[x1][y1][bt] += 1 + dp[x][y][rg];
            dp[x1][y1][both] += 1 + dp[x][y][rg];
            Ans += 1 + dp[x][y][rg];
          } else
            break;
          x1--;
          y1--;
        }
        x1 = x - 1, y1 = y - 1;
        while (x1 > 0 && y1 > 0) {
          if (!vis[x1][y1]) {
            if (!vis[x1 + 1][y1]) {
              Ans += 1 + dp[x][y][bt];
              dp[x1][y1][bt] += dp[x][y][both];
              dp[x1][y1][both] += dp[x][y][both];
            }
            if (!vis[x1][y1 + 1]) {
              Ans += 1 + dp[x][y][rg];
              dp[x1][y1][rg] += dp[x][y][both];
              dp[x1][y1][both] += dp[x][y][both];
            }
            if (vis[x1][y1 + 1] && vis[x1 + 1][y1]) break;
          } else
            break;
          x1--;
          y1--;
        }
      }
      cout << Ans << '\n';
    }
  }
  return 0;
}
