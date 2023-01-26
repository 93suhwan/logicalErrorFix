#include <bits/stdc++.h>
using namespace std;
int fun() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> mp;
  for (int i = 0; i < n * m; i++) {
    int x;
    cin >> x;
    mp[x].push_back(i + 1);
  }
  int arr[n][m];
  int x = 0, y = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int cnt = it->second.size();
    vector<int> x1 = it->second;
    while (cnt) {
      int maxadd = m - y;
      if (cnt >= maxadd) {
        for (int j = m - 1; j >= y; j--) {
          arr[x][j] = x1[0];
          x1.erase(x1.begin());
        }
        x++;
        y = 0;
        cnt -= maxadd;
        continue;
      } else {
        for (int j = cnt + y - 1; j >= y; j--) {
          arr[x][j] = x1[0];
          x1.erase(x1.begin());
        }
        y += cnt;
        if (y == m) {
          y = 0;
          x++;
        }
        cnt = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<pair<int, int>> vt;
    for (int j = 0; j < m; j++) {
      vt.push_back({arr[i][j], j + 1});
    }
    sort(vt.begin(), vt.end());
    vector<int> add;
    add.push_back(vt[0].second);
    for (int j = 1; j < m; j++) {
      int pos = lower_bound(add.begin(), add.end(), vt[j].second) - add.begin();
      ans += pos;
      if (pos == add.size()) {
        add.push_back(vt[j].second);
        continue;
      }
      add.insert(add.begin() + pos, vt[j].second);
    }
  }
  cout << ans << endl;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) fun();
}
