#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long bp(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b % 2) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
const long long inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  long long lo, hi, mset = inf, madd = 0, val = -inf;
  Node(long long lo, long long hi) : lo(lo), hi(hi) {}
  Node(vector<long long>& v, long long lo, long long hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      long long mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = max(l->val, r->val);
    } else
      val = v[lo];
  }
  long long query(long long L, long long R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return max(l->query(L, R), r->query(L, R));
  }
  void set(long long L, long long R, long long x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R)
      mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void add(long long L, long long R, long long x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = max(l->val, r->val);
    }
  }
  void push() {
    if (!l) {
      long long mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};
long long n, l;
vector<vector<long long>> adj;
long long timer;
vector<long long> tin, tout;
vector<vector<long long>> up;
void dfs(long long v, long long p) {
  tin[v] = timer;
  ++timer;
  up[v][0] = p;
  for (long long i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (long long u : adj[v]) {
    if (u != p) dfs(u, v);
  }
  tout[v] = timer;
}
bool is_ancestor(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (long long i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void preprocess(long long root) {
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<long long>(l + 1));
  dfs(root, root);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> n >> q;
  long long a[n];
  Node tre(0, n);
  for (long long x = 0; x < n; x++) {
    cin >> a[x];
  }
  long long u, v;
  adj.resize(n);
  for (long long x = 0; x < n - 1; x++) {
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  preprocess(0);
  for (long long x = 0; x < n; x++) {
    tre.add(tin[x], tout[x], abs(a[x]));
  }
  long long c;
  for (long long x = 0; x < q; x++) {
    cin >> c >> u >> v;
    if (c == 1) {
      --u;
      tre.add(tin[u], tout[u], abs(v) - abs(a[u]));
      a[u] = v;
    } else {
      --u;
      --v;
      long long f = lca(u, v);
      long long i = tre.query(tin[u], tin[u] + 1);
      long long j = tre.query(tin[v], tin[v] + 1);
      long long k = tre.query(tin[f], tin[f] + 1);
      long long g = i + j - (2 * k);
      g += abs(a[f]);
      g *= 2;
      g -= (abs(a[u]) + abs(a[v]));
      cout << g << "\n";
    }
  }
}
