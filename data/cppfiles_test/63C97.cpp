#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int n, m[2], w[2][MAX + 1], par[2][MAX + 1], u, v;
vector<pair<int, int> > res;
int findRoot(const int& flag, const int& u) {
  if (par[flag][u] == u) return u;
  return par[flag][u] = findRoot(flag, par[flag][u]);
}
bool canConnect(const int& flag, int u, int v) {
  u = findRoot(flag, u);
  v = findRoot(flag, v);
  return u != v;
}
void connect(const int& flag, int u, int v) {
  u = findRoot(flag, u);
  v = findRoot(flag, v);
  if (u == v) return;
  if (w[flag][u] < w[flag][v]) swap(u, v);
  w[flag][u] += w[flag][v];
  par[flag][v] = u;
}
int main() {
  scanf("%d %d %d", &n, &m[0], &m[1]);
  for (int i = 1; i <= n; ++i) {
    w[0][i] = w[1][i] = 1;
    par[0][i] = par[1][i] = i;
  }
  for (int flag = 0; flag < 2; ++flag)
    for (int i = 0; i < m[flag]; ++i) {
      scanf("%d %d", &u, &v);
      connect(flag, u, v);
    }
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (canConnect(0, i, j) && canConnect(1, i, j)) {
        connect(0, i, j);
        connect(1, i, j);
        res.push_back(pair<int, int>(i, j));
      }
  printf("%d\n", res.size());
  for (const pair<int, int>& item : res)
    printf("%d %d\n", item.first, item.second);
  return 0;
}
