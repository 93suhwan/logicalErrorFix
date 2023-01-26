#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryIndexedTree {
 private:
  static const int N = 1 << 20;
  int n;
  int c[N];

 public:
  void Build(int n) {
    this->n = n;
    for (int i = 0; i <= n; i++) c[i] = 0;
  }
  void Add(int x, int v) {
    for (x++; x <= n; x += x & -x) c[x] += v;
  }
  T Sum(int x) {
    T ret = 0;
    for (x++; x; x -= x & -x) ret += c[x];
    return ret;
  }
};
class DisjointSet {
 private:
  int n;
  vector<int> pa;

 public:
  void Build(int n) {
    this->n = n;
    pa.resize(n);
    for (int i = 0; i < n; i++) pa[i] = i;
  }
  int Find(int x) { return x == pa[x] ? x : pa[x] = Find(pa[x]); }
  bool Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) return false;
    pa[fx] = fy;
    return true;
  }
};
const int N = 3e5, Q = 5e5;
int n;
vector<pair<int, int> > G[N];
vector<pair<int, int> > queries[N];
int f[N];
int pa[N], pre[N], post[N];
int dfs_clock;
DisjointSet ds;
int u[Q], v[Q], x[Q];
int lca[Q];
bool ans[Q];
BinaryIndexedTree<int> bit;
void dfs(int u, int fa = -1) {
  pre[u] = dfs_clock++;
  for (auto [v, qid] : queries[u]) {
    int fv = ds.Find(v);
    if (v != fv) lca[qid] = fv;
  }
  for (auto [v, qid] : G[u]) {
    if (v == fa) continue;
    f[v] = f[u] ^ x[qid];
    pa[v] = u;
    dfs(v, u);
    ds.Union(v, u);
  }
  post[u] = dfs_clock;
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  ds.Build(n);
  for (int i = 0; i < q; i++) {
    cin >> u[i] >> v[i] >> x[i];
    u[i]--, v[i]--;
    if (ds.Union(u[i], v[i])) {
      ans[i] = true;
      G[u[i]].emplace_back(v[i], i);
      G[v[i]].emplace_back(u[i], i);
    } else {
      queries[u[i]].emplace_back(v[i], i);
      queries[v[i]].emplace_back(u[i], i);
    }
  }
  ds.Build(n);
  for (int i = 0; i < n; i++) pre[i] = -1;
  for (int i = 0; i < n; i++)
    if (pre[i] == -1) {
      pa[i] = -1;
      dfs(i);
      f[i] = 0;
    }
  bit.Build(dfs_clock);
  for (int i = 0; i < q; i++) {
    if (ans[i]) continue;
    int U = u[i], V = v[i];
    if ((x[i] ^ f[U] ^ f[V]) != 1) continue;
    int LCA = lca[i];
    int s = bit.Sum(LCA);
    if (bit.Sum(pre[U]) != s || bit.Sum(pre[V]) != s) continue;
    ans[i] = true;
    for (int st : {U, V}) {
      for (int i = st; i != LCA; i = pa[i]) {
        assert(i != -1);
        bit.Add(pre[i], +1);
        bit.Add(post[i], -1);
      }
    }
  }
  for (int i = 0; i < q; i++) puts(ans[i] ? "YES" : "NO");
}
