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
long long p, q, E = 0, Res, n, m;
vector<long long> vis[2][2][N];
void dfs(long long x, long long y, long long dx, long long dy, long long sx,
         long long sy, long long sdx, long long sdy, long long tx, long long ty,
         long long f, long long cur = 1) {
  if (x == 1) dx = 1;
  if (y == 1) dy = 1;
  if (x == n) dx = -1;
  if (y == m) dy = -1;
  if (vis[dx + 1 >> 1][dy + 1 >> 1][x][y] && f > 0) {
    E = (Res + cur * f) % Mod;
    E = (E * poww((1 - cur + Mod) % Mod, -1, Mod)) % Mod;
    return;
  }
  if (x == tx || y == ty) {
    Res = (Res + (((p * cur) % Mod) * f) % Mod) % Mod;
    cur = (cur * q) % Mod;
  }
  vis[dx + 1 >> 1][dy + 1 >> 1][x][y] = 1;
  dfs(x + dx, y + dy, dx, dy, sx, sy, sdx, sdy, tx, ty, f + 1, cur);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long T = 1;
  long long Case = 1;
  cin >> T;
  while (T--) {
    long long x, y, tx, ty;
    cin >> n >> m >> x >> y >> tx >> ty >> p;
    Res = E = 0;
    q = 100 - p;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 1; k <= n; k++) {
          for (int l = 0; l <= m; l++) {
            vis[i][j][k].push_back(0);
          }
        }
      }
    }
    p = (p * poww(100, -1, Mod)) % Mod;
    q = (q * poww(100, -1, Mod)) % Mod;
    long long dx = 1, dy = 1;
    if (x == n) dx = -1;
    if (y == m) dy = -1;
    dfs(x, y, dx, dy, x, y, dx, dy, tx, ty, 0);
    cout << E << '\n';
    for (int i = 0; i <= n; i++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++) vis[k][l][i].clear();
  }
  return 0;
}
