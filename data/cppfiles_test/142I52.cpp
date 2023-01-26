#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
int main() {
  fast();
  int t, m, n, i, j, res1, res2, mn, mx;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    mx = 1000000007;
    vector<vector<int>> v(m, vector<int>(n));
    vector<vector<pair<int, int>>> vv(n);
    set<int> st;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) cin >> v[i][j];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        vv[i].push_back({v[j][i], j});
      }
    }
    for (i = 0; i < n; i++) {
      sort(vv[i].begin(), vv[i].end(), comp);
      mx = min(vv[i][0].first, mx);
      st.insert(vv[i][0].second);
    }
    if (st.size() < n)
      cout << mx << '\n';
    else {
      res1 = 0;
      for (i = 0; i < n; i++) {
        mn = 1000000007;
        for (j = 0; j < n; j++) {
          if (i == vv[j][1].second) continue;
          mn = min(mn, vv[j][1].first);
        }
        res1 = max(mn, res1);
      }
      res2 = 1000000007;
      for (i = 0; i < n; i++) {
        mn = 1000000007;
        for (j = 0; j < n; j++) {
          if (i == vv[j][0].second) continue;
          mn = min(mn, vv[j][0].first);
        }
        res2 = min(mn, res2);
      }
      cout << min(res1, res2) << '\n';
    }
  }
}
