#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
const int LOG = 18;
vector<pair<int, int>> gr[maxn];
int pleasure[maxn];
int parent[LOG][maxn];
int max_edge[LOG][maxn];
int depth[maxn];
void lca_dfs(int v, int par = -1) {
  for (auto pr : gr[v]) {
    int to = pr.first;
    if (to == par) {
      continue;
    }
    parent[0][to] = v;
    max_edge[0][to] = pr.second;
    depth[to] = depth[v] + 1;
    for (int i = 1; i < LOG; ++i) {
      parent[i][to] = parent[i - 1][parent[i - 1][to]];
      max_edge[i][to] =
          max(max_edge[i - 1][to], max_edge[i - 1][parent[i - 1][to]]);
    }
    lca_dfs(to, v);
  }
}
int GoUp(int v, int len) {
  for (int i = 0; i < LOG; ++i) {
    if ((len >> i) & 1) {
      v = parent[i][v];
    }
  }
  return v;
}
int GetMaxUp(int v, int len) {
  int res = 0;
  for (int i = 0; i < LOG; ++i) {
    if ((len >> i) & 1) {
      res = max(res, max_edge[i][v]);
      v = parent[i][v];
    }
  }
  return res;
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) {
    swap(x, y);
  }
  x = GoUp(x, depth[x] - depth[y]);
  if (x == y) {
    return x;
  }
  for (int i = LOG - 1; i >= 0; --i) {
    if (parent[i][x] != parent[i][y]) {
      x = parent[i][x];
      y = parent[i][y];
    }
  }
  return parent[0][x];
}
int GetMaxOnPath(int x, int y) {
  int lca = LCA(x, y);
  return max(GetMaxUp(x, depth[x] - depth[lca]),
             GetMaxUp(y, depth[y] - depth[lca]));
}
struct Node {
  vector<int> vertices;
  int value;
  int mx_edge;
  Node() {}
  Node(int v) : value(pleasure[v]), mx_edge(0) { vertices = {v}; }
  void Add(int v) {
    vertices.emplace_back(v);
    mx_edge = max(mx_edge, GetMaxOnPath(v, vertices[0]));
  }
  int Get(int v) { return max(mx_edge, GetMaxOnPath(v, vertices[0])); }
};
int dsu[2 * maxn];
Node node[2 * maxn];
int answer[maxn][2];
void InitDSU(int n) {
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
    node[i] = Node(i);
  }
}
int GetDSU(int v) {
  if (v == dsu[v]) {
    return v;
  }
  return dsu[v] = GetDSU(dsu[v]);
}
void UnionDSU(int x, int y) {
  x = GetDSU(x);
  y = GetDSU(y);
  if (x == y) {
    return;
  }
  if (node[x].value < node[y].value) {
    dsu[x] = y;
  } else if (node[x].value == node[y].value) {
    if (node[x].vertices.size() < node[y].vertices.size()) {
      for (auto v : node[x].vertices) {
        node[y].Add(v);
      }
      dsu[x] = y;
    } else {
      for (auto v : node[y].vertices) {
        node[x].Add(v);
      }
      dsu[y] = x;
    }
  } else {
    dsu[y] = x;
  }
}
void SolveTest() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> pleasure[i];
  }
  vector<pair<int, pair<int, int>>> events;
  for (int i = 0; i < n - 1; ++i) {
    int x, y, c, t;
    cin >> x >> y >> c >> t;
    x--, y--;
    gr[x].emplace_back(y, t);
    gr[y].emplace_back(x, t);
    events.emplace_back(c, make_pair(x, y));
  }
  lca_dfs(0);
  for (int i = 0; i < q; ++i) {
    int c, v;
    cin >> c >> v;
    v--;
    events.emplace_back(c, make_pair(-v - 1, i));
  }
  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  InitDSU(n);
  for (int i = 0; i < events.size(); ++i) {
    int v = events[i].second.first;
    if (v >= 0) {
      UnionDSU(v, events[i].second.second);
    } else {
      v = -(v + 1);
      int id = events[i].second.second;
      int par = GetDSU(v);
      answer[id][0] = node[par].value;
      answer[id][1] = node[par].Get(v);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << answer[i][0] << ' ' << answer[i][1] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  t = 1;
  for (int i = 0; i < t; ++i) {
    SolveTest();
  }
  return 0;
}
