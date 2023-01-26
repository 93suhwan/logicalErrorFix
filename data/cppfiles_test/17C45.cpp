#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 998244353;
int N;
ll tree[400000] = {0};
void clearTree(int i = 1) {
  if (i >= 2 * N || tree[i] == 0) return;
  tree[i] = 0;
  clearTree(i << 1);
  clearTree(i << 1 | 1);
}
void build() {
  for (int i = N - 1; i; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
}
void modify(int i, int e) {
  i += N;
  tree[i] = (tree[i] + e) % mod;
  while (i >>= 1) {
    tree[i] = (tree[i << 1] + tree[i << 1 | 1]) % mod;
  }
}
ll query(int l, int r) {
  ll result = 0;
  for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
    result += (l & 1 ? tree[l++] : 0) + (r & 1 ? 0 : tree[r--]);
    result %= mod;
  }
  return result;
}
void solver() {
  int n;
  cin >> n;
  vl a(n);
  for (auto &i : a) cin >> i;
  vl b = a;
  sort(b.begin(), b.end());
  map<int, int> m;
  int idx = 0;
  for (int i = 0; i < n;) {
    int cur = b[i];
    while (i < n && b[i] == cur) ++i;
    m[cur] = (idx++);
  }
  for (int i = 0; i < n; ++i) {
    a[i] = m[a[i]];
  }
  N = idx;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    res += min(query(0, a[i] - 1), query(a[i] + 1, N - 1));
    modify(a[i], 1);
  }
  cout << res << "\n";
  clearTree();
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool mt = 1;
  int tests = 1;
  if (mt) cin >> tests;
  for (int tt = 1; tt <= tests; ++tt) {
    solver();
  }
  return 0;
}
