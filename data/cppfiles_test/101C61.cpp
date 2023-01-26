#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int tt;
int n, m, k;
set<int> rw, cl;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> k;
    rw.clear();
    cl.clear();
    for (int i = 1; i <= n; i++) {
      int r;
      cin >> r;
      rw.insert(r);
    }
    for (int i = 1; i <= m; i++) {
      int c;
      cin >> c;
      cl.insert(c);
    }
    vector<pair<int, int>> row, col;
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      if (rw.find(x) != rw.end() and cl.find(y) != cl.end()) continue;
      if (rw.find(x) != rw.end()) row.push_back({y, x});
      if (cl.find(y) != cl.end()) col.push_back({x, y});
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    cl.insert(1e9);
    int lst = -1;
    ll ans = 0;
    for (auto i : cl) {
      int l_idx =
          lower_bound(row.begin(), row.end(), make_pair(lst, 0)) - row.begin();
      int r_idx = lower_bound(row.begin(), row.end(), make_pair(i, 0)) -
                  row.begin() - 1;
      if (l_idx >= 0 and r_idx < (int)row.size() and l_idx <= r_idx) {
        map<int, int> un;
        for (int j = l_idx; j <= r_idx; j++) un[row[j].second]++;
        ll cnt = 0, way = 0;
        for (auto j : un) {
          way += (1ll * cnt * j.second);
          cnt += j.second;
        }
        ans += way;
      }
      lst = i;
    }
    rw.insert(1e9);
    lst = -1;
    for (auto i : rw) {
      int l_idx =
          lower_bound(col.begin(), col.end(), make_pair(lst, 0)) - col.begin();
      int r_idx = lower_bound(col.begin(), col.end(), make_pair(i, 0)) -
                  col.begin() - 1;
      if (l_idx >= 0 and r_idx < (int)col.size() and l_idx <= r_idx) {
        map<int, int> un;
        for (int j = l_idx; j <= r_idx; j++) un[col[j].second]++;
        ll cnt = 0, way = 0;
        for (auto j : un) {
          way += (1ll * cnt * j.second);
          cnt += j.second;
        }
        ans += way;
      }
      lst = i;
    }
    cout << ans << '\n';
  }
}
