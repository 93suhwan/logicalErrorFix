#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 10;
template <class T>
struct FenwickTree {
 public:
  T* tree;
  T mxbit = 1;
  int size;
  T prefixSum(int i) {
    i++;
    T ret = 0;
    while (i > 0) {
      ret += tree[i];
      i -= (i & -i);
    }
    return ret;
  }
  T rangeSum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }
  int lbound(T x) {
    int res = 0;
    T curr = 0;
    T bit = mxbit;
    while (bit) {
      if ((res | bit) <= size && curr + tree[res | bit] < x) {
        res |= bit;
        curr += tree[res];
      }
      bit >>= 1;
    }
    return res;
  }
  void update(int i, T delta) {
    i++;
    while (i <= size) {
      tree[i] += delta;
      i += (i & -i);
    }
  }
  FenwickTree(int sz) {
    size = sz;
    tree = new T[size + 1];
    memset(tree, 0, (size + 1) * sizeof(T));
    while ((mxbit << 1) <= size) mxbit <<= 1;
  }
  FenwickTree(vector<T>& arr) : FenwickTree(arr.size()) {
    for (int i = 0; i < size; i++) update(i, arr[i]);
  }
};
FenwickTree<int> tree(MX);
vector<int> adj[MX], at[MX];
vector<tuple<int, int, int>> queries[MX];
int val[MX], occ[MX], f[MX], finv[MX], ans[MX];
int n, q;
void swp(int u, int v) {
  int fu = f[u], fv = f[v];
  f[u] = fv;
  f[v] = fu;
  finv[fu] = v;
  finv[fv] = u;
}
void moo(int va, int a, int b) {
  if (a < b)
    occ[va]++;
  else
    occ[va]--;
  if (a > 0) {
    swp(at[a].back(), finv[va]);
    at[a].pop_back();
    tree.update(a, -1);
  }
  if (b > 0) {
    at[b].push_back(finv[va]);
    tree.update(b, 1);
  }
}
void add(int v) { moo(val[v], occ[val[v]], occ[val[v]] + 1); }
void rmv(int v) { moo(val[v], occ[val[v]], occ[val[v]] - 1); }
void dfs(int curr) {
  add(curr);
  for (int v : adj[curr]) dfs(v);
  for (auto [l, k, i] : queries[curr]) {
    k += tree.prefixSum(l - 1);
    int j = tree.lbound(k);
    if (j > n)
      ans[i] = -1;
    else
      ans[i] = f[at[j].back()] + 1;
  }
  rmv(curr);
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      int w;
      cin >> w;
      w--;
      val[i] = w;
      f[w] = w;
      finv[w] = w;
    }
    for (int i = 0; i < n - 1; i++) {
      int p;
      cin >> p;
      p--;
      adj[p].push_back(i + 1);
    }
    for (int i = 0; i < q; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      v--;
      queries[v].push_back(make_tuple(l, k, i));
    }
    dfs(0);
    for (int i = 0; i < q; i++) cout << ans[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      queries[i].clear();
      at[i + 1].clear();
      tree.tree[i + 1] = 0;
      occ[i] = 0;
    }
  }
}
