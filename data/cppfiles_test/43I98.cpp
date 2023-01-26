#include <bits/stdc++.h>
using namespace std;
class DSU {
 public:
  vector<int> _parent;
  int parent(int v) {
    return _parent[v] < 0 ? v : (_parent[v] = parent(_parent[v]));
  }
  void merge(int v, int u) {
    if ((v = parent(v)) == (u = parent(u))) return;
    if (_parent[v] < _parent[u]) swap(v, u);
    _parent[u] += _parent[v];
    _parent[v] = u;
  }
  DSU(int size) { _parent.resize(size, -1); }
};
class Node {
  int left;
  int right;
  int sum;
  Node* left_child;
  Node* right_child;

 public:
  Node(int l, int r) {
    sum = 0;
    right = r;
    left = l;
    if (l == r) {
      return;
    }
    int mid = (r + l) / 2;
    left_child = new Node(l, mid);
    right_child = new Node(mid + 1, r);
    sum += right_child->sum + left_child->sum;
  }
  void add(int l, int r, int x) {
    if (right < l || left > r) {
      return;
    } else if (right <= r && left >= l) {
      sum += x;
    } else {
      right_child->add(l, r, x);
      left_child->add(l, r, x);
      sum = left_child->sum + right_child->sum;
    }
  }
  int query(int l, int r) {
    if (right < l || left > r) {
      return 0;
    } else if (right <= r && left >= l) {
      return sum;
    } else {
      return right_child->query(l, r) + left_child->query(l, r);
    }
  }
};
struct edge {
  int u;
  int v;
  int w;
  int id;
  edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};
const int N = 3e5 + 10, Q = 5e5 + 10;
vector<edge> cycle_edges;
int n, q, f[N][20], first[N], last[N], root[N], Xor[N], depth[N], tim = 1;
vector<pair<int, int>> adj[N];
bool visited[N], ans[Q];
void dfs(int v, int p, int r) {
  visited[v] = true;
  root[v] = r;
  first[v] = tim++;
  f[v][0] = p;
  for (int i = 1; i < 20; i++) {
    f[v][i] = f[f[v][i - 1]][i - 1];
  }
  for (auto x : adj[v]) {
    int u = x.first;
    int w = x.second;
    if (u != p) {
      depth[u] = depth[v] + 1;
      Xor[u] = Xor[v] ^ w;
      dfs(u, v, r);
    }
  }
  last[v] = tim++;
}
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  int k = depth[a] - depth[b];
  for (int i = 0; i < 20; i++) {
    if (k & (1 << i)) {
      a = f[a][i];
    }
  }
  if (a == b) return a;
  for (int i = 19; i >= 0; i--) {
    if (f[a][i] != f[b][i]) {
      a = f[a][i];
      b = f[b][i];
    }
  }
  return f[a][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  DSU dsu(n);
  for (int i = 0; i < q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    if (dsu.parent(u) == dsu.parent(v)) {
      cycle_edges.push_back(edge(u, v, w, i));
      continue;
    }
    ans[i] = true;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    dsu.merge(u, v);
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, i, i);
    }
  }
  Node sum(0, tim);
  for (int i = 0; i < cycle_edges.size(); i++) {
    int u, v, w, id;
    u = cycle_edges[i].u;
    v = cycle_edges[i].v;
    w = cycle_edges[i].w;
    id = cycle_edges[i].id;
    bool flag = false;
    if ((Xor[u] ^ Xor[v] ^ w) == 1) {
      int a = lca(u, v);
      int s1 = sum.query(0, first[v]);
      int s2 = sum.query(0, first[u]);
      int s3 = sum.query(0, first[a]);
      if (s1 + s2 - 2 * s3 == 0) {
        flag = true;
        while (u != a) {
          sum.add(first[u], first[u], 1);
          sum.add(last[u], last[u], -1);
          u = f[u][0];
        }
        while (v != a) {
          sum.add(first[v], first[v], 1);
          sum.add(last[v], last[v], -1);
          v = f[v][0];
        }
        sum.add(first[a], first[a], 1);
        sum.add(last[a], last[a], -1);
      }
    }
    if (flag) {
      ans[id] = true;
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
