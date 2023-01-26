#include <bits/stdc++.h>
const int N = 3e5 + 5;
using namespace std;
struct edge {
  int x, y, z;
} g[N << 1];
vector<pair<int, int> > ed;
vector<int> ans, ans2;
int k[N], d[N], t[N][3], fa[N], f[N][2], v[N];
int su = 0;
bool vi[N];
bool fl = 1;
inline int read() {
  char h = getchar();
  int y = 0, q = 1;
  while (h < '0' || h > '9') {
    if (h == '-') q = -1;
    h = getchar();
  }
  while (h >= '0' && h <= '9') y = y * 10 + h - '0', h = getchar();
  return y * q;
}
inline void add(int a, int b) {
  g[++su] = (edge){k[a], b};
  k[a] = su;
}
void dfs(int x) {
  vi[x] = 1;
  for (int i = k[x]; i; i = g[i].x) {
    int y = g[i].y;
    if (vi[y]) continue;
    ed.push_back(make_pair(x, y));
    dfs(y);
  }
}
void dfs2(int x) {
  for (int i = k[x]; i; i = g[i].x) {
    int y = g[i].y;
    fa[y] = x;
    d[y] = d[x] + 1;
    dfs2(y);
  }
}
void dfs3(int x) {
  for (int i = k[x]; i; i = g[i].x) {
    int y = g[i].y;
    dfs3(y);
    v[x] ^= v[y];
    g[i].z = v[y];
    if (v[y]) fl = 0;
  }
}
void dfs4(int x) {
  for (int i = k[x]; i; i = g[i].x) {
    int y = g[i].y, z = g[i].z;
    dfs4(y);
    int t0 = min(f[x][1] + f[y][1] + (z == 0) + 1,
                 f[x][0] + min(f[y][0] + (z == 1), f[y][1] + 1 + (z == 0)));
    int t1 = min(f[x][0] + f[y][1] + (z == 0),
                 f[x][1] + min(f[y][0] + (z == 1), f[y][1] + 1 + (z == 0)));
    f[x][0] = t0;
    f[x][1] = t1;
  }
}
inline int lca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  while (d[a] > d[b]) a = fa[a];
  while (a != b) a = fa[a], b = fa[b];
  return a;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int a = read(), b = read();
    add(a, b);
    add(b, a);
  }
  dfs(1);
  memset(k, 0, sizeof k);
  su = 0;
  for (int i = 0; i < ed.size(); i++) add(ed[i].first, ed[i].second);
  dfs2(1);
  int q = read();
  for (int i = 1; i <= q; i++) {
    int a = read(), b = read();
    int l = lca(a, b);
    t[i][0] = a;
    t[i][1] = b;
    t[i][2] = l;
    v[b] ^= 1;
    v[a] ^= 1;
  }
  dfs3(1);
  if (fl) {
    puts("YES");
    for (int i = 1; i <= q; i++) {
      ans.clear();
      ans2.clear();
      for (int j = t[i][0]; j != t[i][2]; j = fa[j]) {
        ans.push_back(j);
        if (ans.size() > n) return 114514;
      }
      ans.push_back(t[i][2]);
      for (int j = t[i][1]; j != t[i][2]; j = fa[j]) {
        ans2.push_back(j);
        if (ans2.size() > n) return 114514;
      }
      cout << ans.size() + ans2.size() << "\n";
      for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      for (int i = ans2.size() - 1; ~i; i--) cout << ans2[i] << " ";
      cout << "\n";
    }
    return 0;
  } else {
    puts("NO");
    dfs4(1);
    cout << f[1][0] << "\n";
  }
}
