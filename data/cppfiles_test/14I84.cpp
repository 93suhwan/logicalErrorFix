#include <bits/stdc++.h>
const int mod = 998244353, MAXN = 1e5 + 1;
const long long inf = 1e18;
const double eps = 1e-12;
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> ans;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int mi = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[mi]) mi = j;
    }
    if (mi != i) {
      ans.push_back({{i, mi}, mi - i});
      vector<int> tmp(mi - i + 1);
      for (int k = i, t = mi - i; k <= mi; k++) {
        tmp[t++] = a[k];
        t %= mi - i;
      }
      for (int k = i, t = 0; k <= mi; k++) {
        a[k] = tmp[t++];
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' '
         << ans[i].second << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  signed t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
