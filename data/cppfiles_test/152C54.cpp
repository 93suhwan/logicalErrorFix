#include <bits/stdc++.h>
const int INF = 2e9;
inline int Max(const int &a, const int &b) { return a > b ? a : b; }
inline int Min(const int &a, const int &b) { return a > b ? b : a; }
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
using namespace std;
const int N = 1e6 + 7;
int T, n;
int p[N], b[N];
struct jgt {
  int j, k, ls, tp;
} q[N * 4];
int cnt;
vector<int> f[N];
void dfs(int id, int i) {
  if (!i) return;
  b[i] = q[id].tp * p[i];
  dfs(q[id].ls, i - 1);
}
int a, j, k;
int ax, _ax, xa, x_a;
int axid, _axid, xaid, x_aid;
void solve() {
  n = read();
  for (int i = 1; i <= n; ++i) p[i] = read();
  for (int i = 1; i <= n; ++i) f[i].clear();
  q[cnt = 1] = {-p[1], -INF, 0, -1};
  f[1].push_back(1);
  for (int i = 2; i <= n; ++i) {
    if (f[i - 1].empty()) {
      puts("NO");
      return;
    }
    a = p[i];
    ax = _ax = xa = x_a = INF;
    axid = _axid = xaid = x_aid = 0;
    for (int id : f[i - 1]) {
      j = q[id].j, k = q[id].k;
      if (k < -a) {
        if (j < -a) {
          if (k < _ax) _ax = k, _axid = id;
        } else {
          if (j < x_a) x_a = j, x_aid = id;
        }
      }
      if (k < a) {
        if (j < a) {
          if (k < ax) ax = k, axid = id;
        } else {
          if (j < xa) xa = j, xaid = id;
        }
      }
    }
    if (ax < INF) {
      q[++cnt] = {a, ax, axid, 1};
      f[i].push_back(cnt);
    }
    if (xa < INF) {
      q[++cnt] = {xa, a, xaid, 1};
      f[i].push_back(cnt);
    }
    if (_ax < INF) {
      q[++cnt] = {-a, _ax, _axid, -1};
      f[i].push_back(cnt);
    }
    if (x_a < INF) {
      q[++cnt] = {x_a, -a, x_aid, -1};
      f[i].push_back(cnt);
    }
  }
  if (f[n].empty()) {
    puts("NO");
  } else {
    puts("YES");
    dfs(f[n][0], n);
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
    puts("");
  }
}
int main() {
  T = read();
  for (int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
