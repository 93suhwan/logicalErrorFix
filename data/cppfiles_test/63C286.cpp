#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int N = 1e3 + 7;
int n;
vector<int> edg1[N], edg2[N];
bool check[N][N];
int m1, m2;
int dad2[N], dad1[N];
int d1[N], d2[N];
int dem1, dem2;
bool vis1[N], vis2[N];
vector<ii> res;
int DSU1(int x) {
  if (dad1[x] != x) dad1[x] = DSU1(dad1[x]);
  return dad1[x];
}
int DSU2(int x) {
  if (dad2[x] != x) dad2[x] = DSU2(dad2[x]);
  return dad2[x];
}
void DFS1(int u) {
  vis1[u] = 1;
  d1[u] = dem1;
  for (int v : edg1[u]) {
    if (vis1[v]) continue;
    DFS1(v);
  }
}
void DFS2(int u) {
  vis2[u] = 1;
  d2[u] = dem2;
  for (int v : edg2[u]) {
    if (vis2[v]) continue;
    DFS2(v);
  }
}
int main() {
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    edg1[u].push_back(v);
    edg1[v].push_back(u);
    check[u][v] = check[v][u] = 1;
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    edg2[u].push_back(v);
    edg2[v].push_back(u);
    check[u][v] = check[v][u] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (vis1[i] == 0) {
      dem1++;
      DFS1(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (vis2[i] == 0) {
      dem2++;
      DFS2(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    dad1[i] = i;
    dad2[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (check[i][j])
        continue;
      else {
        int u = DSU1(d1[i]);
        int v = DSU1(d1[j]);
        if (u == v) continue;
        int pu = DSU2(d2[i]);
        int pv = DSU2(d2[j]);
        if (pu == pv) continue;
        res.push_back({i, j});
        check[i][j] = check[j][i] = 1;
        dad1[v] = u;
        dad2[pv] = pu;
      }
    }
  }
  cout << res.size() << '\n';
  for (ii i : res) {
    cout << i.first << " " << i.second << '\n';
  }
}
