#include <bits/stdc++.h>
using namespace std;
vector<int> A;
vector<int> d;
vector<int> P;
vector<int> g;
vector<vector<int>> G;
int bestu, bestv, bestw, bestvv;
void dfs(int x, int v, int n) {
  for (int i = 0; i < G[x].size(); ++i) {
    int y = G[x][i];
    int u = g[y];
    if (u >= 0) {
      if (d[u] < 0) {
        d[u] = v;
        P[u] = y;
        P[y] = x;
        dfs(u, v, n);
      }
    } else if (A[y] + A[v] > bestw) {
      bestw = A[y] + A[v];
      bestu = x;
      bestv = y;
      bestvv = v;
    }
  }
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(1 << n);
  for (int i = 0; i < a.size(); ++i) scanf("%d", &a[i]);
  vector<array<int, 3>> edges;
  {
    vector<int> bc(1 << n);
    for (int i = 1; i < bc.size(); ++i) bc[i] = bc[i & (i - 1)] + 1;
    array<int, 3> e;
    for (int i = 0; i < bc.size(); ++i) {
      if (bc[i] % 2 == 0)
        for (int j = 0; j < n; ++j) {
          e[0] = -(a[i] + a[i ^ (1 << j)]);
          e[1] = i;
          e[2] = i ^ (1 << j);
          edges.push_back(e);
        }
    }
  }
  int edges_cnt = min(2 * n * k + 1, (int)edges.size());
  nth_element(edges.begin(), edges.begin() + edges_cnt, edges.end());
  vector<int> idx(1 << n, -1);
  int vert = 0;
  for (int i = 0; i < edges_cnt; ++i)
    if (idx[edges[i][1]] < 0) {
      A.push_back(a[edges[i][1]]);
      idx[edges[i][1]] = vert;
      ++vert;
    }
  G.resize(vert);
  int vert2 = vert;
  for (int i = 0; i < edges_cnt; ++i) {
    if (idx[edges[i][2]] < 0) {
      A.push_back(a[edges[i][2]]);
      idx[edges[i][2]] = vert2;
      ++vert2;
    }
    G[idx[edges[i][1]]].push_back(idx[edges[i][2]]);
  }
  vector<char> was(vert);
  g.assign(vert2, -1);
  P.resize(vert2);
  int res = 0;
  for (int i = 0; i < k; ++i) {
    d.assign(vert, -1);
    bestw = -1;
    for (int j = 0; j < vert; ++j) {
      int x = j;
      if (!was[x] && d[x] < 0) {
        P[x] = -1;
        d[x] = x;
        dfs(x, x, n);
      }
    }
    if (bestw >= 0) {
      res += bestw;
      g[bestv] = bestu;
      was[bestvv] = 1;
      for (int x = P[bestu]; x >= 0;) {
        int y = P[x];
        g[x] = y;
        x = P[y];
      }
    } else
      break;
  }
  printf("%d\n", res);
}
int main() {
  solve();
  return 0;
}
