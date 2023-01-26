#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
using ll = long long;
using ld = long double;
using ull = unsigned long long;
ll const inf = 1e18;
random_device rd;
mt19937 mersenne(rd());
struct SegmentTree {
  struct Node {
    ll sum = 0;
    Node(ll SUM = 0) : sum(SUM) {}
  };
  Node merge(Node n1, Node n2) { return Node(n1.sum + n2.sum); }
  vector<Node> tree;
  ll n;
  SegmentTree(vector<ll>& start) {
    n = start.size();
    tree.resize(n * 4 + 228);
    init(0, 0, n, start);
  }
  void init(ll v, ll l, ll r, vector<ll>& start) {
    if (l + 1 == r) {
      tree[v] = Node(start[l]);
      return;
    }
    ll m = (l + r) / 2;
    init(v * 2 + 1, l, m, start);
    init(v * 2 + 2, m, r, start);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
  }
  void change(ll v, ll l, ll r, ll pos, ll val) {
    if (l + 1 == r && l == pos) {
      tree[v] = Node(val);
      return;
    }
    if (l > pos || r <= pos) {
      return;
    }
    ll m = (l + r) / 2;
    change(v * 2 + 1, l, m, pos, val);
    change(v * 2 + 2, m, r, pos, val);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
  }
  void change(ll pos, ll val) { change(0, 0, n, pos, val); }
  Node query(ll v, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
      return tree[v];
    }
    if (r <= ql || qr <= l) {
      return Node(0);
    }
    ll m = (l + r) / 2;
    return merge(query(v * 2 + 1, l, m, ql, qr),
                 query(v * 2 + 2, m, r, ql, qr));
  }
  Node query(ll ql, ll qr) { return query(0, 0, n, ql, qr); }
};
template <class T>
struct SparseTable {
  ll n, k;
  vector<T> a;
  vector<vector<T>> sparse;
  SparseTable(vector<T>& start) {
    n = start.size();
    k = 0;
    for (ll d = 1; d <= n; d *= 2, ++k) {
    }
    a.assign(start.begin(), start.end());
    sparse.assign(n, vector<T>(k));
    countSparse();
  }
  void countSparse() {
    for (int i = 0; i < n; ++i) {
      sparse[i][0] = a[i];
    }
    for (int j = 1; j < k; ++j) {
      for (int i = 0; i < n; ++i) {
        ll d = (1ll << (j - 1));
        sparse[i][j] = min(sparse[i][j - 1], sparse[min(n - 1, i + d)][j - 1]);
      }
    }
  }
  T query(ll l, ll r) {
    ll d = 1, t = 0;
    while (2 * d < r - l) {
      d *= 2;
      ++t;
    }
    return min(sparse[l][t], sparse[r - d][t]);
  }
};
ll mod = 998244353;
ll merge(vector<ll> const& dp, vector<ll> const& a, ll ind, ll b) {
  if (ind == -1) return b;
  if (b >= *max_element(a.begin(), a.end())) return dp[ind] * (b - 1);
  return dp[ind] * b - merge(dp, a, ind - 1, b);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<ll> dp(n, 0);
  for (ll i = 0; i < n; ++i) {
    dp[i] = merge(dp, a, i - 1, a[i]);
  }
  cout << dp[n - 1];
  return 0;
}
