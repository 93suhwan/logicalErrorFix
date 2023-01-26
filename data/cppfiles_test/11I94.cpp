#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct info {
  int maxi = 0;
};
struct segtree {
  int n;
  vector<info> t;
  segtree(int n) {
    this->n = n + 1;
    t.resize(n * 4);
  }
  void Merge(info &node, info &l, info &r) { node.maxi = max(l.maxi, r.maxi); }
  void update(int node, int l, int r, int i, int j, int add) {
    if (l > j || r < i) {
      return;
    }
    if (l >= i && r <= j) {
      t[node].maxi = add;
      return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, j, add);
    update(node * 2 + 1, mid + 1, r, i, j, add);
    Merge(t[node], t[node * 2], t[node * 2 + 1]);
  }
  void update(int l, int add) { update(1, 0, n, l, l, add); }
  info query(int node, int l, int r, int i, int j) {
    if (l > j || r < i) {
      info x;
      return x;
    }
    if (l >= i && r <= j) {
      return t[node];
    }
    int mid = (l + r) / 2;
    info x = query(node * 2, l, mid, i, j);
    info y = query(node * 2 + 1, mid + 1, r, i, j);
    info ret;
    Merge(ret, x, y);
    return ret;
  }
  int query(int l, int r) {
    info ret = query(1, 0, n, l, r);
    return ret.maxi;
  }
};
int dp[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = i - a[i];
  }
  int ans = 0;
  dp[0] = 0;
  segtree seg(N - 2);
  for (int i = 1; i <= n; i++) {
    if (b[i] < 0) continue;
    dp[i] = max(dp[i], seg.query(0, min(b[i], a[i] - 1)) + 1);
    seg.update(max(a[i], b[i]), dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}
