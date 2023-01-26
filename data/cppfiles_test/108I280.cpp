#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int ans[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int i, n;
    cin >> n;
    for (i = 1; i <= n; ++i) cin >> a[i];
    for (i = 1; i <= n; ++i) cin >> b[i];
    if (1 == n)
      cout << "1\n";
    else {
      vector<pair<int, int> > v, bb;
      for (i = 1; i <= n; ++i) v.push_back({a[i], i}), bb.push_back({b[i], i});
      sort(v.begin(), v.end());
      sort(bb.begin(), bb.end());
      int st = 0;
      while (st < n) {
        if (v[st].second == bb[st].second)
          ++st;
        else
          break;
      }
      for (i = st; i < n; ++i) ans[v[i].second] = 1;
      ans[v.back().second] = 1;
      for (i = 1; i <= n; ++i) cout << ans[i];
      cout << "\n";
    }
  }
  return 0;
}
