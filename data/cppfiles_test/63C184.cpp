#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& gr, int u) {
  if (gr[u] < 0) return u;
  return gr[u] = find(gr, gr[u]);
}
void Union(vector<int>& gr, int u, int v) {
  int paru = find(gr, u);
  int parv = find(gr, v);
  if (gr[paru] < gr[parv]) {
    gr[paru] = +gr[parv];
    gr[parv] = paru;
  } else {
    gr[parv] = +gr[paru];
    gr[paru] = parv;
  }
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<int> gr1(n + 1, -1);
  vector<int> gr2(n + 1, -1);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    Union(gr1, u, v);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    Union(gr2, u, v);
  }
  vector<vector<int>> edges;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (find(gr1, i) != find(gr1, j) && find(gr2, i) != find(gr2, j)) {
        Union(gr1, i, j);
        Union(gr2, i, j);
        edges.push_back({i, j});
      }
    }
  }
  cout << edges.size() << endl;
  for (int i = 0; i < edges.size(); i++) {
    cout << edges[i][0] << " " << edges[i][1] << endl;
  }
  return 0;
}
