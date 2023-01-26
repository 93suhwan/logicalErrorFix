#include <bits/stdc++.h>
using namespace std;
void abc() { cout << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cout << a << ' ', abc(b...);
}
template <typename T>
void printv(T l, T r) {
  for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
template <typename T>
ostream& operator<<(ostream& o, vector<T> a) {
  bool is = false;
  if (a.empty()) return o << "{}";
  for (T i : a) {
    o << (is ? ' ' : '{'), is = true, o << i;
  }
  return o << '}';
}
template <typename T>
struct vv : vector<vector<T>> {
  vv(int n, int m, T v) : vector<vector<T>>(n, vector<T>(m, v)) {}
  vv() {}
};
template <typename T>
struct vvv : vector<vv<T>> {
  vvv(int n, int m, int k, T v) : vector<vv<T>>(n, vv<T>(m, k, v)) {}
  vvv() {}
};
const int mod = 998244353, N = 200001, logN = 18, K = 1 << 9, G = 3;
vector<int> adj[N];
int jump[N][logN], val[N][logN], in[N], out[N], dep[N], _t;
void dfs_lca(int v, int pa) {
  dep[v] = ~pa ? dep[pa] + 1 : 0;
  jump[v][0] = pa;
  val[v][0] = adj[v].size() - (pa != -1);
  in[v] = _t++;
  for (int u : adj[v])
    if (u != pa) {
      dfs_lca(u, v);
    }
  out[v] = _t++;
}
bool anc(int u, int v) { return in[u] <= in[v] && out[u] >= out[v]; }
int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (int i = logN - 1; ~i; --i) {
    int k = jump[u][i];
    if (~k && !anc(k, v)) {
      u = k;
    }
  }
  return jump[u][0];
}
long long int query_sum(int u, int v, int k) {
  assert(anc(v, u));
  int ans = 0, d = dep[u] - dep[v];
  for (int i = 0; i < logN; ++i)
    if (d >> i & 1) {
      ans += val[u][i];
      u = jump[u][i];
    }
  return ans - 1ll * d * k;
}
void build_lca(int n) {
  dfs_lca(0, -1);
  for (int j = 1; j < logN; ++j) {
    for (int i = 0; i < n; ++i) {
      int k = jump[i][j - 1];
      if (k == -1) {
        jump[i][j] = -1;
      } else {
        jump[i][j] = jump[k][j - 1];
        if (~jump[i][j]) val[i][j] = val[i][j - 1] + val[k][j - 1];
      }
    }
  }
}
vector<int> in_virtual_tree;
vector<pair<int, long long int>> virtual_tree[N];
long long int dp[N];
int get(int u, int v) {
  if (u == -1) return v;
  if (v == -1) return u;
  if (dep[u] < dep[v]) return u;
  return v;
}
struct Seg {
  int l, r, m, v;
  Seg* ch[2];
  Seg(int _l, int _r) : l(_l), r(_r), m(l + r >> 1), v(-1) {
    if (r - l > 1) {
      ch[0] = new Seg(l, m);
      ch[1] = new Seg(m, r);
    }
  }
  void pull() { v = get(ch[0]->v, ch[1]->v); }
  void set(int p, int _v) {
    if (r - l == 1)
      v = _v;
    else
      ch[p >= m]->set(p, _v), pull();
  }
  int query(int a, int b) {
    if (a <= l && r <= b) return v;
    int ans = -1;
    if (a < m) ans = get(ans, ch[0]->query(a, b));
    if (m < b) ans = get(ans, ch[1]->query(a, b));
    return ans;
  }
};
Seg* root;
void dfs_dp(int v = in_virtual_tree[0], int pa = -1) {
  dp[v] = 0;
  for (auto [u, w] : virtual_tree[v])
    if (u != pa) {
      dfs_dp(u, v);
      dp[v] = max(dp[v], dp[u] + w);
    }
}
void reset() {
  while (!in_virtual_tree.empty()) {
    int v = in_virtual_tree.back();
    in_virtual_tree.pop_back();
    virtual_tree[v].clear(), root->set(in[v], -1);
  }
}
void build_virtual_tree(vector<int> v, int k) {
  reset();
  int m = v.size();
  sort(v.begin(), v.end(), [&](int i, int j) { return in[i] < in[j]; });
  for (int i = 1; i < m; ++i) {
    v.push_back(lca(v[i - 1], v[i]));
  }
  sort(v.begin(), v.end(), [&](int i, int j) { return in[i] < in[j]; });
  v.resize(unique(v.begin(), v.end()) - v.begin());
  in_virtual_tree = v;
  for (int i : in_virtual_tree) {
    root->set(in[i], i);
  }
  void(0);
  for (int i = 1; i < in_virtual_tree.size(); ++i) {
    int x = lca(in_virtual_tree[i - 1], in_virtual_tree[i]),
        y = in_virtual_tree[i];
    if (dep[x] < dep[y]) swap(x, y);
    long long int d = query_sum(x, y, k);
    void(0);
    virtual_tree[x].emplace_back(y, d), virtual_tree[y].emplace_back(x, d);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; ++i) {
    cin >> u >> v, --u, --v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  build_lca(n);
  cin >> q;
  vector<vector<pair<int, int>>> Q(200002);
  for (int i = 0, v, k; i < q; ++i) {
    cin >> v >> k, --v;
    Q[++k].emplace_back(v, i);
  }
  vector<int> v(n);
  iota(v.begin(), v.end(), 0);
  sort(v.begin(), v.end(), [&](int i, int j) { return val[i][0] > val[j][0]; });
  vector<int> cur_vertex;
  vector<long long int> ans(q, 0);
  root = new Seg(0, 2 * n);
  for (int k = 200001, i = 0; k; --k) {
    while (i < n && val[v[i]][0] > k) {
      cur_vertex.push_back(v[i++]);
    }
    if (i) build_virtual_tree(cur_vertex, k), dfs_dp();
    for (auto [v, id] : Q[k]) {
      int u = root->query(in[v], out[v]);
      void(0);
      if (u == -1)
        ans[id] = val[v][0];
      else {
        ans[id] = dp[u] + val[v][0] + query_sum(u, v, k);
      }
      void(0);
    }
  }
  for (long long int i : ans) cout << i << '\n';
}
