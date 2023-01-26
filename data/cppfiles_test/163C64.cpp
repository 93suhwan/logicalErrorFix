#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
constexpr int KINF = 0x3f3f3f3f;
constexpr int INF = 0x7f7f7f7f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  auto inv = [&](long long x, long long y = mod - 2) {
    long long res = 1;
    while (y) {
      if (y & 1) (res *= x) %= mod;
      (x *= x) %= mod;
      y >>= 1;
    }
    return res;
  };
  while (_--) {
    int n, m;
    cin >> n >> m;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    long long p;
    cin >> p;
    int dx = 1, dy = 1;
    set<tuple<int, int, int, int>> vis;
    int x = sx, y = sy;
    int ti = 0;
    vector<int> tag(4 * n * m);
    while (true) {
      if (x + dx < 1 || x + dx > n) dx *= -1;
      if (y + dy < 1 || y + dy > m) dy *= -1;
      if (vis.count({x, y, dx, dy})) break;
      vis.insert({x, y, dx, dy});
      if (x == tx || y == ty) tag[ti] = 1;
      x += dx;
      y += dy;
      ++ti;
    }
    long long E = 0;
    long long np = 1;
    (p *= inv(100)) %= mod;
    for (int i = (int)0; i < (int)ti; ++i) {
      if (tag[i]) {
        E = (E + (np * p) % mod * i) % mod;
        (np *= (mod + 1 - p)) %= mod;
      }
    }
    p = (mod + 1 - np) % mod;
    long long ans =
        (E * inv(p) % mod + ((mod + 1 - p) * ti % mod) * inv(p)) % mod;
    cout << ans << "\n";
  }
  return 0;
}
