#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int powm(int x, int y) {
  if (y == 0) return 1;
  int d = powm(x, y / 2);
  d = (d * 1ll * d) % MOD;
  if (y % 2) d = (d * 1ll * x) % MOD;
  return d;
}
vector<vector<vector<vector<bool>>>> used;
int n, m;
int rx, ry;
int pb;
void fix(int x, int y, int& dx, int& dy) {
  if (x + dx >= m || x + dx < 0) dx = -dx;
  if (y + dy >= n || y + dy < 0) dy = -dy;
}
pair<int, int> dfs(int y, int x, int dy, int dx) {
  fix(x, y, dx, dy);
  int kxi = (dx == 1 ? 1 : 0);
  int kyi = (dy == 1 ? 1 : 0);
  used[y][x][kyi][kxi] = true;
  int xi = x + dx;
  int yi = y + dy;
  fix(xi, yi, dx, dy);
  kxi = (dx == 1 ? 1 : 0);
  kyi = (dy == 1 ? 1 : 0);
  if (used[yi][xi][kyi][kxi])
    return (x == rx || y == ry ? make_pair(pb, pb) : make_pair(1, 1));
  else {
    auto p = dfs(yi, xi, dy, dx);
    if (x != rx && y != ry) {
      return {(1 + p.first) % MOD, p.second};
    } else {
      int u = p.first;
      u = (u + 1) % MOD;
      u = (u * 1ll * pb) % MOD;
      int v = (p.second * 1ll * pb) % MOD;
      return {u, v};
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    used.clear();
    int x, y;
    int pp;
    cin >> n >> m >> y >> x >> ry >> rx >> pp;
    --y;
    --x;
    --ry;
    --rx;
    pb = (MOD + 1 - (pp * 1ll * powm(100, MOD - 2)) % MOD) % MOD;
    used.assign(n, vector<vector<vector<bool>>>(
                       m, vector<vector<bool>>(2, vector<bool>(2))));
    auto p = dfs(y, x, 1, 1);
    int ans = p.first;
    int dv = (MOD + 1 - p.second) % MOD;
    ans = (ans * 1ll * powm(dv, MOD - 2)) % MOD;
    cout << ans << endl;
  }
}
