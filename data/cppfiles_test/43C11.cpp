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
int dsu[2 * maxn];
int sons[2 * maxn][2];
int init_size;
int dsu_size;
void InitDSU(int n) {
  dsu_size = init_size = n;
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
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
  int v = dsu_size;
  dsu_size++;
  dsu[v] = dsu[x] = dsu[y] = v;
  sons[v][0] = x;
  sons[v][1] = y;
}
vector<pair<int, int>> queries[2 * maxn];
int answer[maxn][2];
struct Node {
  vector<int> vertices;
  int value;
  int mx_edge;
  Node(int v) : value(pleasure[v]), mx_edge(0) { vertices = {v}; }
  void Add(int v) {
    vertices.emplace_back(v);
    mx_edge = max(mx_edge, GetMaxOnPath(v, vertices[0]));
  }
  int Get(int v) { return max(mx_edge, GetMaxOnPath(v, vertices[0])); }
};
Node DsuDfs(int v) {
  if (v < init_size) {
    for (auto pr : queries[v]) {
      int id = pr.second;
      answer[id][0] = pleasure[v];
      answer[id][1] = 0;
    }
    return Node(v);
  }
  int l = sons[v][0];
  int r = sons[v][1];
  Node lf = DsuDfs(l);
  Node rg = DsuDfs(r);
  if (lf.value < rg.value) {
    lf = std::move(rg);
  } else if (lf.value == rg.value) {
    if (lf.vertices.size() < rg.vertices.size()) {
      for (auto vrt : lf.vertices) {
        rg.Add(vrt);
      }
      lf = std::move(rg);
    } else {
      for (auto vrt : rg.vertices) {
        lf.Add(vrt);
      }
    }
  }
  for (auto pr : queries[v]) {
    int id = pr.second;
    answer[id][0] = lf.value;
    answer[id][1] = lf.Get(pr.first);
  }
  return lf;
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
      queries[GetDSU(v)].emplace_back(v, events[i].second.second);
    }
  }
  DsuDfs(GetDSU(0));
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
