#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long llINF = 0x3f3f3f3f3f3f3f3f;
long long make_compiler_happy() { return INF ^ 3 ^ maxn ^ mod ^ llINF; }
long long fpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return fpow(x, mod - 2); }
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
using node = tuple<int, int, int, int>;
void solve() {
  int n, m;
  int rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  rb--, cb--, rd--, cd--;
  p = (100 - p) * inv(100) % mod;
  vector<vector<array<array<node, 2>, 2>>> go(
      n, vector<array<array<node, 2>, 2>>(m));
  vector<vector<array<array<int, 2>, 2>>> vis(
      n, vector<array<array<int, 2>, 2>>(m));
  long long len = 0;
  function<node(int, int, int, int, long long)> dfs =
      [&](int x, int y, int dx, int dy, long long tim) {
        if ((x == rd || y == cd) && vis[x][y][dx][dy]) {
          len = tim - vis[x][y][dx][dy];
          return make_tuple(x, y, dx, dy);
        }
        vis[x][y][dx][dy] = tim;
        int xx = dx ? x + 1 : x - 1;
        int yy = dy ? y + 1 : y - 1;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m)
          go[x][y][dx][dy] = dfs(xx, yy, dx, dy, tim + 1);
        else if (xx >= 0 && xx < n)
          return go[x][y][dx][dy] = dfs(x, y, dx, !dy, tim);
        else if (yy >= 0 && yy < m)
          return go[x][y][dx][dy] = dfs(x, y, !dx, dy, tim);
        else
          return go[x][y][dx][dy] = dfs(x, y, !dx, !dy, tim);
        if (x == rd || y == cd) {
          return make_tuple(x, y, dx, dy);
        } else {
          return go[x][y][dx][dy];
        }
      };
  int pp = 1, sum = 0;
  dfs(rb, cb, 1, 1, 1);
  node st;
  if (rb == rd || cb == cd) {
    st = make_tuple(rb, cb, 1, 1);
  } else {
    st = go[rb][cb][1][1];
  }
  node now = st;
  long long ans;
  {
    auto [x, y, dx, dy] = now;
    ans = vis[x][y][dx][dy] - 1;
  }
  do {
    auto [x, y, dx, dy] = now;
    node nxt = go[x][y][dx][dy];
    auto [nx, ny, ndx, ndy] = nxt;
    long long t = vis[nx][ny][ndx][ndy] - vis[x][y][dx][dy];
    if (t <= 0) t += len;
    sum = (sum + t * pp % mod * p % mod) % mod;
    pp = (long long)pp * p % mod;
    now = nxt;
  } while (now != st);
  pp = (1 + mod - pp) % mod;
  ((void)0), ((void)0), ((void)0);
  cout << (ans + sum * inv(pp)) % mod << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  for (int kase = (1); kase <= (T); kase++) {
    solve();
  }
}
