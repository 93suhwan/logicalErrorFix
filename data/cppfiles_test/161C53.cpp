#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> l(n + 1), r(n + 1);
    vector<pair<int, int>> v;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      v.emplace_back(make_pair(a, b));
      l[a].emplace_back(b);
      r[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
      sort(l[i].begin(), l[i].end());
      sort(r[i].begin(), r[i].end());
    }
    for (auto it : v) {
      int L = it.first;
      int R = it.second;
      if (L == R) {
        ans.emplace_back(L);
        continue;
      }
      int pos = lower_bound(l[L].begin(), l[L].end(), R) - l[L].begin();
      pos--;
      if (pos < 0) {
        ans.emplace_back(L);
      } else
        ans.emplace_back(l[L][pos] + 1);
    }
    for (int i = 0; i < v.size(); i++) {
      cout << v[i].first << ' ' << v[i].second << ' ' << ans[i] << '\n';
    }
  }
  return 0;
}
