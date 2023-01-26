#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
const int B = 18;
int timer;
int par[N + 1][B + 1];
bool fix[N + 1], xorup[N + 1];
vector<pair<int, int> > v[N + 1];
int cmp[N + 1], sz[N + 1], tin[N + 1], tout[N + 1], sum[N + 1], parent[N + 1];
bool isp(int parent, int child) {
  return parent && child && tin[parent] <= tin[child] &&
         tout[child] <= tout[parent];
}
int lca(int a, int b) {
  if (isp(a, b)) return a;
  for (int i = B; i >= 0; i--)
    if (!isp(par[a][i], b)) a = par[a][i];
  return par[a][0];
}
void goup(int from, int to) {
  int d = 0;
  while (true) {
    if (fix[from] == 0) {
      fix[from] = 1;
      d++;
    }
    sum[from] += d;
    if (from == to) break;
    from = par[from][0];
  }
}
void dfs(int p, int q, int c, int prnt) {
  tin[p] = timer++;
  cmp[p] = c;
  parent[p] = prnt;
  par[p][0] = q;
  for (int i = 1; i <= B; i++) par[p][i] = par[par[p][i - 1]][i - 1];
  for (int i = 0; i < v[p].size(); i++)
    if (v[p][i].first != q) {
      xorup[v[p][i].first] = (xorup[p] ^ v[p][i].second);
      sum[v[p][i].first] = sum[p] + fix[v[p][i].first];
      dfs(v[p][i].first, p, c, prnt);
    }
  tout[p] = timer++;
}
int get_lca(int a, int b) {
  vector<int> v;
  while (a != 0) {
    v.push_back(a);
    a = par[parent[a]][0];
  }
  while (b != 0) {
    for (int i = 0; i < v.size(); i++)
      if (parent[b] == parent[v[i]]) return lca(b, v[i]);
    b = par[parent[b]][0];
  }
  return 0;
}
bool solve(int from, int to, int val) {
  if (cmp[from] == cmp[to]) {
    if ((xorup[from] ^ xorup[to] ^ val) == 0) return 0;
    int top = get_lca(from, to);
    int black = sum[from] - sum[top] + sum[to] - sum[top] - fix[from] -
                fix[to] + fix[top];
    if (fix[from] || fix[to]) {
      if (black > 0) return 0;
    } else {
      if (black > 1) return 0;
    }
    goup(from, top);
    goup(to, top);
    return 1;
  }
  if (sz[cmp[from]] > sz[cmp[to]]) swap(from, to);
  sz[cmp[to]] += sz[cmp[from]];
  v[from].push_back(make_pair(to, val));
  v[to].push_back(make_pair(from, val));
  xorup[from] = (xorup[to] ^ val);
  sum[from] = sum[to] + fix[from];
  dfs(from, to, cmp[to], from);
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= N; i++) {
    cmp[i] = i;
    sz[i] = 1;
  }
  while (m--) {
    if (m == -1) {
      for (int i = 1; i <= n; i++)
        cout << cmp[i] << " " << par[i][0] << " " << parent[i] << endl;
    }
    int a, b, c;
    cin >> a >> b >> c;
    bool ok = solve(a, b, c);
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
