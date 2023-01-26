#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  int s = int(sqrt(q)) + 1;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    r[p[i]] = i;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
    for (int j = 0; j < s; ++j) {
      a[i] = p[a[i]];
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      swap(p[x], p[y]);
      swap(r[x], r[y]);
      int ax = x;
      for (int j = 0; j < s; ++j) {
        ax = p[ax];
      }
      for (int i = 0; i <= s; ++i) {
        a[x] = ax;
        x = r[x];
        ax = r[ax];
      }
      int ay = y;
      for (int j = 0; j < s; ++j) {
        ay = p[ay];
      }
      for (int i = 0; i <= s; ++i) {
        a[y] = ay;
        y = r[y];
        ay = r[ay];
      }
    } else {
      int i, k;
      cin >> i >> k;
      --i;
      while (k >= s) {
        i = a[i];
        k -= s;
      }
      while (k > 0) {
        i = p[i];
        k--;
      }
      cout << i + 1 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
