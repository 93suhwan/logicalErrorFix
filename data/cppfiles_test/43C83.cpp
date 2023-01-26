#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
const int B = 18;
int timerin, timerout;
int tin[N + 1], tout[N + 1];
int comp[N + 1];
int par[N + 1][B + 1];
int sum[N + 1], xorup[N + 1];
int f[N + 2];
void upd(int x, int d) {
  for (; x <= N; x += (x & -x)) f[x] += d;
}
int cnt(int x) {
  int ans = 0;
  for (; x > 0; x -= (x & -x)) ans += f[x];
  return ans;
}
vector<pair<int, int> > v[N + 1];
bool isp(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
int lca(int a, int b) {
  if (isp(a, b)) return a;
  for (int i = B; i >= 0; i--)
    if (par[a][i] && !isp(par[a][i], b)) a = par[a][i];
  return par[a][0];
}
int dfs(int p, int parent) {
  tin[p] = ++timerin;
  par[p][0] = parent;
  for (int i = 1; i <= B; i++) par[p][i] = par[par[p][i - 1]][i - 1];
  for (int i = 0; i < v[p].size(); i++)
    if (v[p][i].first != parent) {
      xorup[v[p][i].first] = xorup[p] ^ v[p][i].second;
      int d = dfs(v[p][i].first, p);
      sum[p] += d + 1;
    }
  tout[p] = ++timerout;
  return sum[p];
}
void update(int p, int top) {
  for (int t = p; t != top; t = par[t][0]) {
    upd(tin[t], 1);
    upd(tin[t] + sum[t] + 1, -1);
  }
}
bool solve(int a, int b, int x) {
  if (x == -1) return 1;
  if ((xorup[a] ^ xorup[b] ^ x) == 0) return 0;
  int top = lca(a, b);
  if (cnt(tin[a]) + cnt(tin[b]) > 2 * cnt(tin[top])) return 0;
  update(a, top);
  update(b, top);
  return 1;
}
int parent(int p) {
  if (comp[p] != p) comp[p] = parent(comp[p]);
  return comp[p];
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) comp[i] = i;
  int a[m], b[m], x[m];
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", a + i, b + i, x + i);
    if (parent(a[i]) != parent(b[i])) {
      comp[parent(a[i])] = parent(b[i]);
      v[a[i]].push_back(make_pair(b[i], x[i]));
      v[b[i]].push_back(make_pair(a[i], x[i]));
      x[i] = -1;
    }
  }
  for (int i = 1; i <= n; i++)
    if (parent(i) == i) dfs(i, 0);
  for (int i = 0; i < m; i++)
    if (solve(a[i], b[i], x[i]))
      printf("YES\n");
    else
      printf("NO\n");
  return 0;
}
