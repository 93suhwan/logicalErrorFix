#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int st[4 * maxn], v[maxn];
void build(int p, int l, int r) {
  if (l == r) {
    st[p] = v[l];
    return;
  }
  build(2 * p, l, (l + r) / 2);
  build(2 * p + 1, (l + r) / 2 + 1, r);
  st[p] = st[2 * p] + st[2 * p + 1];
}
int query(int p, int l, int r, int i, int j) {
  if (r < i or j < l) {
    return 0;
  }
  if (i <= l and r <= j) {
    return st[p];
  }
  int x = query(2 * p, l, (l + r) / 2, i, j);
  int y = query(2 * p + 1, (l + r) / 2 + 1, r, i, j);
  return x + y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(v, 0, sizeof(v));
    memset(st, 0, sizeof(st));
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      int p;
      if (s[i] == '-') {
        p = -1;
      } else {
        p = 1;
      }
      if (i % 2 == 0) {
        v[i] = p;
      } else {
        v[i] = (-1) * p;
      }
    }
    build(1, 0, n - 1);
    while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = query(1, 0, n - 1, l - 1, r - 1);
      while (ans > 2) {
        ans -= 2;
      }
      while (ans < 0) {
        ans += 2;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
