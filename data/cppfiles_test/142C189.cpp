#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > p(n, vector<int>(m));
  for (auto& v : p)
    for (auto& el : v) cin >> el;
  int l = 0, r = int(1e9) + 10;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    bool res = false;
    vector<vector<int> > a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = p[i][j] >= mid;
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cnt[j] += a[i][j];
    bool f = true;
    for (int i = 0; i < m; i++)
      if (cnt[i] == 0) {
        f = false;
        break;
      }
    if (f) {
      for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) cur += a[i][j];
        if (cur >= 2) res = true;
      }
    }
    if (res)
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
