#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<pair<int, int> > e[N];
int n, m, x, y, ans[N][2], S[N], X[N], Y[N], Z[N], w[N], i, j, k, d[N], fa[N],
    f[N][20], v[N][20];
pair<int, int> a[N], b[N], mx[N];
void ins(int u, int v, int w) {
  e[u].push_back(pair<int, int>(v, w));
  e[v].push_back(pair<int, int>(u, w));
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void dfs(int x, int fa) {
  for (int i = 1; (1 << i) <= d[x]; ++i)
    f[x][i] = f[f[x][i - 1]][i - 1],
    v[x][i] = max(v[f[x][i - 1]][i - 1], v[x][i - 1]);
  for (auto& y : e[x]) {
    int a = y.first, b = y.second;
    if (a == fa) continue;
    d[a] = d[x] + 1;
    f[a][0] = x;
    v[a][0] = b;
    dfs(a, x);
  }
}
int get(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  int t = d[x] - d[y], res = 0;
  for (int i = 19; i >= 0; --i)
    if (t >> i & 1) res = max(res, v[x][i]), x = f[x][i];
  for (int i = 19; i >= 0; --i)
    if (f[x][i] != f[y][i])
      res = max(res, max(v[x][i], v[y][i])), x = f[x][i], y = f[y][i];
  if (x != y) res = max(res, max(v[x][0], v[y][0]));
  return res;
}
int main() {
  for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i)
    scanf("%d", w + i), fa[i] = i, mx[i] = pair<int, int>(i, i);
  for (i = 1; i < n; ++i) {
    int u, v, x, y;
    scanf("%d%d%d%d", &u, &v, &x, &y);
    ins(u, v, y);
    X[i] = u;
    Y[i] = v;
    Z[i] = x;
    a[i] = pair<int, int>(Z[i], i);
  }
  dfs(1, 0);
  for (i = 1; i <= m; ++i) scanf("%d%d", &b[i].first, S + i), b[i].second = i;
  sort(b + 1, b + m + 1);
  sort(a + 1, a + n);
  for (i = n - 1, j = m; i || j;)
    if (a[i].first >= b[j].first) {
      k = a[i].second;
      x = find(X[k]);
      y = find(Y[k]);
      if (w[mx[x].first] < w[mx[y].first]) swap(x, y);
      if (w[mx[x].first] == w[mx[y].first]) {
        vector<int> d;
        d.push_back(get(mx[x].first, mx[x].second));
        d.push_back(get(mx[y].first, mx[y].second));
        d.push_back(get(mx[x].first, mx[y].first));
        d.push_back(get(mx[x].first, mx[y].second));
        d.push_back(get(mx[x].second, mx[y].first));
        d.push_back(get(mx[x].second, mx[y].second));
        sort(d.begin(), d.end());
        if (get(mx[y].first, mx[y].second) == d.back()) mx[x] = mx[y];
        if (get(mx[x].first, mx[y].first) == d.back())
          mx[x] = pair<int, int>(mx[x].first, mx[y].first);
        if (get(mx[x].first, mx[y].second) == d.back())
          mx[x] = pair<int, int>(mx[x].first, mx[y].second);
        if (get(mx[x].second, mx[y].first) == d.back())
          mx[x] = pair<int, int>(mx[x].second, mx[y].first);
        if (get(mx[x].second, mx[y].second) == d.back())
          mx[x] = pair<int, int>(mx[x].second, mx[y].second);
      }
      fa[y] = x;
      i--;
    } else {
      x = find(S[k = b[j].second]);
      ans[k][0] = w[mx[x].first];
      ans[k][1] = max(get(S[k], mx[x].first), get(S[k], mx[x].second));
      j--;
    }
  for (i = 1; i <= m; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
}
