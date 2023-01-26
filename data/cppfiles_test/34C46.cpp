#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("179")
#pragma GCC optimize("unroll-loops")
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<bool>> a(5001, vector<bool>(10000, false));
  vector<vector<int>> b(5001);
  for (int i = 0; i <= 5000; ++i) {
    a[i][0] = 1, b[i].push_back(0);
  }
  vector<int> ans;
  ans.push_back(0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (auto j : b[x]) {
      ans.push_back(j ^ x);
      for (int k = x + 1; k <= 5000; ++k) {
        if (a[k][j ^ x]) break;
        b[k].push_back(j ^ x), a[k][j ^ x] = 1;
      }
    }
    b[x].clear();
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i << " ";
}
