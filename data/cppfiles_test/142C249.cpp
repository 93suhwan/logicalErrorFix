#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int m, n;
  cin >> m >> n;
  long long int a[m][n];
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) cin >> a[i][j];
  }
  set<long long int> shop;
  long long int store[n];
  long long int pre[n], suff[n];
  long long int fre[m];
  for (long long int i = 0; i < m; i++) fre[i] = 0;
  for (long long int i = 0; i < n; i++) {
    long long int mx = -1000000000000000;
    for (long long int s : shop) mx = max(mx, a[s][i]);
    pre[i] = mx;
    mx = -1000000000000000;
    set<long long int> temp;
    for (long long int j = 0; j < m; j++) {
      if (a[j][i] > mx) {
        mx = a[j][i];
        temp.clear();
        temp.insert(j);
      } else if (a[j][i] == mx)
        temp.insert(j);
    }
    store[i] = mx;
    for (long long int s : temp) fre[s]++, shop.insert(s);
  }
  for (long long int i = 0; i < m; i++) {
    if (fre[i] > 1) {
      long long int ans = 1000000000000000;
      for (long long int i = 0; i < n; i++) ans = min(ans, store[i]);
      cout << ans << endl;
      return;
    }
  }
  if (shop.size() < n) {
    long long int ans = 1000000000000000;
    for (long long int i = 0; i < n; i++) ans = min(ans, store[i]);
    cout << ans << endl;
    return;
  }
  long long int res = -1000000000000000;
  for (long long int i = 0; i < m; i++) {
    vector<pair<long long int, long long int>> vp;
    for (long long int j = 0; j < n; j++) {
      vp.push_back({a[i][j], j});
    }
    sort(vp.begin(), vp.end());
    long long int ans = min(vp[n - 1].first, vp[n - 2].first);
    long long int x = vp[n - 1].second;
    long long int y = vp[n - 2].second;
    for (long long int j = 0; j < n; j++) {
      if (j == x || j == y) continue;
      ans = min(ans, store[j]);
    }
    res = max(res, ans);
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
