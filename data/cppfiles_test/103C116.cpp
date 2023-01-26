#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, nxt;
} e[4000005];
short deg[4000005];
int head[4000005], cnt, x, y, z;
void add(int x, int y) {
  deg[y]++;
  e[++cnt].v = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}
int n, m;
int dep[4000005];
int vis[4000005];
void init(int u) {
  for (int i = 1; i <= u; i++) {
    e[i].v = e[i].nxt = 0;
    vis[i] = 0;
    deg[i] = 0;
    dep[i] = 0;
    head[i] = 0;
  }
  cnt = 0;
}
int coor(int x, int y) { return (x - 1) * m + y; }
int s = 0, qd = 0;
bool dfs(int u, int d) {
  if (dep[u]) {
    return 0;
  }
  if (vis[u]) {
    qd = d - vis[u];
    s = u;
    dep[u] = qd;
    return 1;
  }
  vis[u] = d;
  if (!head[u]) {
    dep[u] = 1;
    return 0;
  }
  if (dfs(e[head[u]].v, d + 1)) {
    if (s) {
      dep[u] = qd;
    } else
      dep[u] = dep[e[head[u]].v] + 1;
    if (u == s) {
      s = 0;
      return 0;
    } else
      return 1;
  } else {
    dep[u] = dep[e[head[u]].v] + 1;
    return 0;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cerr << t << endl;
    cin >> n >> m;
    init(n * m);
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        if (s[j - 1] == 'U') {
          if (i > 1) {
            add(coor(i, j), coor(i - 1, j));
          }
        }
        if (s[j - 1] == 'R') {
          if (j < m) {
            add(coor(i, j), coor(i, j + 1));
          }
        }
        if (s[j - 1] == 'D') {
          if (i < n) {
            add(coor(i, j), coor(i + 1, j));
          }
        }
        if (s[j - 1] == 'L') {
          if (j > 1) {
            add(coor(i, j), coor(i, j - 1));
          }
        }
      }
    }
    int mx = 0;
    for (int i = 1; i <= n * m; i++) {
      if (!deg[i] and !dep[i]) {
        dfs(i, 1);
        if (dep[mx] < dep[i]) {
          mx = i;
        }
      }
    }
    for (int i = 1; i <= n * m; i++) {
      if (!dep[i]) {
        dfs(i, 1);
        if (dep[mx] < dep[i]) {
          mx = i;
        }
      }
    }
    cout << (mx - 1) / m + 1 << ' ' << (mx - 1) % m + 1 << ' ' << dep[mx]
         << endl;
  }
}
