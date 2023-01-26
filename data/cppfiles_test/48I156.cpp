#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
int get(int v, int l, int r, int ql, int qr) {
  if (l >= qr || ql >= r) return 0;
  if (ql <= l && r <= qr) return tree[v];
  return get(2 * v + 1, l, (l + r) / 2, ql, qr) +
         get(2 * v + 2, (l + r) / 2, r, ql, qr);
}
void upd(int v, int l, int r, int ql, int qr) {
  if (l >= qr || ql >= r) return;
  if (ql <= l && r <= qr) {
    tree[v]++;
    return;
  }
  upd(2 * v + 1, l, (l + r) / 2, ql, qr);
  upd(2 * v + 2, (l + r) / 2, r, ql, qr);
  tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  tree.assign(4 * n, 0);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < n - 1) ans += get(0, 0, n, a[i] + 1, n);
    upd(0, 0, n, a[i], a[i] + 1);
  }
  tree.assign(4 * n, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > 0) ans += get(0, 0, n, 0, a[i]);
    upd(0, 0, n, a[i], a[i] + 1);
  }
  if (ans % 2 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
