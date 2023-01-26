#include <bits/stdc++.h>
using namespace std;
auto fio = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
int32_t main() {
  int n;
  cin >> n;
  vector<int> g(n);
  for (int& x : g) cin >> x;
  vector<vector<int>> idx(8192);
  for (int i = 0; i < n; i++) idx[g[i]].push_back(i);
  vector<int> mn(8192, n);
  mn[0] = -1;
  for (int i = 0; i <= 5000; i++) {
    if (idx[i].empty()) continue;
    for (int j = 0; j < 8192; j++) {
      if (mn[j] <= mn[i ^ j] || mn[i ^ j] >= idx[i].back()) continue;
      auto it = upper_bound(idx[i].begin(), idx[i].end(), mn[i ^ j]);
      if (it != idx[i].end() && *it < mn[j]) mn[j] = *it;
    }
  }
  cout << 8192 - count(mn.begin(), mn.end(), n) << endl;
  for (int i = 0; i < 8192; i++)
    if (mn[i] != n) cout << i << " ";
  cout << endl;
}
