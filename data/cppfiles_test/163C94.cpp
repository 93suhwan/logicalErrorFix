#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, m, T, x, y, a, b, q;
map<pair<pair<int, int>, pair<int, int> >, bool> p;
vector<pair<int, int> > v, e;
long long ksm(long long x, long long y) {
  if (!y) return 1;
  long long res = ksm(x, y / 2);
  res = res * res % mod;
  if (y % 2) res = res * x % mod;
  return res;
}
inline bool ok(int X, int Y) { return (X >= 1 && Y >= 1 && X <= n && Y <= m); }
void solve() {
  cin >> n >> m >> x >> y >> a >> b >> q;
  p.clear();
  long long ans = 0;
  int dx = 1, dy = 1, ox = x, oy = y;
  v.clear();
  e.clear();
  long long A = 1ll * q * ksm(100, mod - 2) % mod,
            B = 1ll * (100 - q) * ksm(100, mod - 2) % mod;
  while (!p[make_pair(make_pair(x, y), make_pair(dx, dy))]) {
    p[make_pair(make_pair(x, y), make_pair(dx, dy))] = true;
    int nx = x + dx, ny = y + dy;
    v.push_back(make_pair(x, y));
    if (!ok(nx, y)) dx = -dx, nx = x + dx;
    if (!ok(x, ny)) dy = -dy, ny = y + dy;
    x = nx, y = ny;
  }
  p.clear();
  while (!p[make_pair(make_pair(x, y), make_pair(dx, dy))]) {
    p[make_pair(make_pair(x, y), make_pair(dx, dy))] = true;
    int nx = x + dx, ny = y + dy;
    e.push_back(make_pair(x, y));
    if (!ok(nx, y)) dx = -dx, nx = x + dx;
    if (!ok(x, ny)) dy = -dy, ny = y + dy;
    x = nx, y = ny;
  }
  p.clear();
  long long c = 1, g = 0;
  swap(v, e);
  for (int i = 0; i < v.size(); i++)
    if (v[i].first == a || v[i].second == b)
      g = (g + c) % mod, c = c * B % mod;
    else
      g = (g + c) % mod;
  ans = g * ksm(1 - c + mod, mod - 2) % mod;
  reverse(e.begin(), e.end());
  for (int i = 0; i < e.size(); i++)
    if (e[i].first == a || e[i].second == b)
      ans = (ans * B % mod + 1) % mod;
    else
      ans = (ans + 1) % mod;
  ans = (ans - 1 + mod) % mod;
  cout << ans << "\n";
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> T;
  while (T--) solve();
  return 0;
}
