#include <bits/stdc++.h>
template <typename _Tp>
void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
const int N = 55, inf = 0x3f3f3f3f;
int d[6], _w[N][N], w[N][N], n, k, ans;
struct DSU {
  int fa[N];
  DSU() { std::iota(fa, fa + N, 0); }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  inline void merge(int x, int y) { fa[find(x)] = find(y); }
};
std::pair<int, int> qaq[15];
int pos;
bool in[N][N], e[N][N][N][N], inq[N][N];
int dg[6], a[N][N];
std::pair<int, int> dis[N][N], _q[N * N * N * N], pre[N][N];
int _l, _r;
bool extend() {
  memset(dg, 0, 24);
  DSU o;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (in[i][j]) {
        if (i <= k) ++dg[i];
        if (j <= k) ++dg[j];
        o.merge(i, j);
      }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) a[i][j] = in[i][j] ? -w[i][j] : w[i][j];
  _l = 1, _r = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) dis[i][j] = {inf, inf};
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (!in[i][j] && o.find(i) != o.find(j) && (i > k || j > k))
        _q[++_r] = {i, j}, dis[i][j] = {a[i][j], 0};
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (in[i][j] && (i > k || j > k)) {
        o = DSU();
        for (int p = 1; p <= n; ++p)
          for (int q = p + 1; q <= n; ++q)
            if (in[p][q] && (i != p || j != q)) o.merge(p, q);
        for (int p = 1; p <= n; ++p)
          for (int q = p + 1; q <= n; ++q)
            if (!in[p][q] && (i > k || j > k) && o.find(p) != o.find(q))
              e[i][j][p][q] = true;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      for (int p = 1; p <= n; ++p)
        for (int q = p + 1; q <= n; ++q) e[i][j][p][q] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (!in[i][j] && (i > k || j > k)) {
        int cnt = 0;
        if (i <= k) cnt += ++dg[i] > d[i];
        if (j <= k) cnt += ++dg[j] > d[j];
        for (int p = 1; p <= n; ++p)
          for (int q = p + 1; q <= n; ++q)
            if (in[p][q] && (p > k || q > k)) {
              int qwq = (p <= k ? (dg[p] == d[p] + 1) : 0) +
                        (q <= k ? (dg[q] == d[q] + 1) : 0);
              if (cnt == qwq) e[i][j][p][q] = true;
            }
        if (i <= k) --dg[i];
        if (j <= k) --dg[j];
      }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) pre[i][j] = {0, 0};
  while (_l != _r + 1) {
    auto [x, y] = _q[_l++];
    inq[x][y] = false;
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (e[x][y][i][j]) {
          std::pair<int, int> qwq = dis[x][y];
          qwq.first += a[i][j], ++qwq.second;
          if (dis[i][j] > qwq) {
            dis[i][j] = qwq, pre[i][j] = {x, y};
            if (!inq[i][j]) _q[++_r] = {i, j}, inq[i][j] = true;
          }
        }
  }
  std::pair<int, int> qwq = {inf, inf};
  int a = 0, b = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (!in[i][j] && (i > k || j > k)) {
        bool flag = (i <= k ? dg[i] + 1 <= d[i] : true) &&
                    (j <= k ? dg[j] + 1 <= d[j] : true);
        if (flag && dis[i][j] < qwq) qwq = dis[i][j], a = i, b = j;
      }
  if (a && b) {
    while (a) in[a][b] ^= 1, std::tie(a, b) = pre[a][b];
    return true;
  }
  return false;
}
std::vector<std::pair<int, int> > E;
void solve() {
  memset(dg, 0, 24), memset(in, 0, sizeof(in));
  int cnt = 0;
  for (auto [x, y] : E) {
    in[x][y] = true, ++cnt;
    if (x <= k) ++dg[x];
    if (y <= k) ++dg[y];
  }
  for (int i = 1; i <= k; ++i)
    if (dg[i] > d[i]) return;
  while (extend()) ++cnt;
  if (cnt == n - 1) {
    int s = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (in[i][j]) s += _w[i][j];
    ans = std::min(ans, s);
  }
}
void dfs(int dep, DSU o) {
  if (dep == pos + 1) return solve();
  dfs(dep + 1, o);
  auto [x, y] = qaq[dep];
  if (o.find(x) != o.find(y))
    o.merge(x, y), E.push_back({x, y}), dfs(dep + 1, o), E.pop_back();
}
int main() {
  read(n, k);
  for (int i = 1; i <= k; ++i) read(d[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) read(_w[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      w[i][j] = i <= k && j <= k ? 1e4 : _w[i][j];
  for (int i = 1; i <= k; ++i)
    for (int j = i + 1; j <= k; ++j) qaq[++pos] = {i, j};
  ans = 1e9, dfs(1, DSU());
  printf("%d\n", ans);
  return 0;
}
