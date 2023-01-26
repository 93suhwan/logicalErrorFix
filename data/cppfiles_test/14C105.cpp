#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  if (is_sorted(v.begin(), v.end())) {
    cout << 0 << "\n";
    ;
    return;
  }
  vector<pair<int, int>> res;
  for (int i = 1; i < n; ++i) {
    if (v[i] >= v[i - 1])
      continue;
    else {
      int l = (int)(lower_bound(v.begin(), v.begin() + i, v[i]) - v.begin());
      sort(v.begin(), v.begin() + i + 1);
      res.push_back({l, i});
    }
  }
  cout << res.size() << "\n";
  ;
  for (auto p : res) {
    cout << p.first + 1 << " " << p.second + 1 << " " << p.second - p.first
         << "\n";
    ;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
