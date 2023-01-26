#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
template <int T>
using A = array<int, T>;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 0;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
const int maxn = 2000;
int dx[maxn + 5], dy[maxn + 5];
int n, m, f[maxn + 5][maxn + 5], deg[maxn + 5][maxn + 5];
A<2> to[maxn + 5][maxn + 5], st[maxn + 5][maxn + 5];
char mp[maxn + 5][maxn + 5];
struct dsu {
  A<2> fa[maxn + 5][maxn + 5];
  int siz[maxn + 5][maxn + 5];
  void clear() {
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(m); j++) fa[i][j] = {i, j}, siz[i][j] = 1;
  }
  A<2> find(A<2> x) {
    return x == fa[x[0]][x[1]] ? x : fa[x[0]][x[1]] = find(fa[x[0]][x[1]]);
  }
  void merge(A<2> x, A<2> y) {
    A<2> fx = find(x), fy = find(y);
    if (fx == fy) return;
    fa[fx[0]][fx[1]] = fy;
    siz[fy[0]][fy[1]] += siz[fx[0]][fx[1]];
  }
} d;
int main() {
  dy['L'] = -1, dy['R'] = 1;
  dx['U'] = -1, dx['D'] = 1;
  for (int T = read(); T; T--) {
    n = read(), m = read(), d.clear();
    for (int i = (1); i <= int(n); i++) cin >> mp[i] + 1;
    for (int i = (1); i <= int(n); i++) {
      for (int j = (1); j <= int(m); j++) {
        f[i][j] = deg[i][j] = 0;
        st[i][j] = {i, j};
        int tx = i + dx[mp[i][j]], ty = j + dy[mp[i][j]];
        if (tx == 0 || ty == 0 || tx == n + 1 || ty == m + 1)
          to[i][j] = {i, j};
        else
          to[i][j] = {tx, ty};
      }
    }
    queue<A<2>> q;
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(m); j++) deg[to[i][j][0]][to[i][j][1]]++;
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(m); j++)
        if (!deg[i][j]) q.push({i, j});
    while (!q.empty()) {
      A<2> u = q.front();
      q.pop();
      if (chkmx(f[to[u[0]][u[1]][0]][to[u[0]][u[1]][1]], f[u[0]][u[1]] + 1)) {
        st[to[u[0]][u[1]][0]][to[u[0]][u[1]][1]] = st[u[0]][u[1]];
      }
      if (--deg[to[u[0]][u[1]][0]][to[u[0]][u[1]][1]] == 0) {
        q.push({to[u[0]][u[1]]});
      }
    }
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(m); j++)
        if (deg[i][j]) d.merge({i, j}, to[i][j]);
    int ans = 0, ansx = -1, ansy = -1;
    for (int i = (1); i <= int(n); i++)
      for (int j = (1); j <= int(m); j++)
        if (deg[i][j]) {
          if (chkmx(ans, f[i][j] + d.siz[d.find({i, j})[0]][d.find({i, j})[1]]))
            ansx = st[i][j][0], ansy = st[i][j][1];
        }
    cout << ansx << ' ' << ansy << ' ' << ans << '\n';
  }
  return 0;
}
