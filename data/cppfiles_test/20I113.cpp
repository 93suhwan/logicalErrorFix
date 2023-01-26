#include <bits/stdc++.h>
using namespace std;
int arr[10010];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n * k; ++i) {
    cin >> arr[i];
  }
  vector<pair<int, int>> ans(n + 1);
  int idx = 0;
  int r = (n + k - 2) / (k - 1);
  vector<bool> find(n + 1, false);
  for (int f = 0; f < n; ++f) {
    int cnt = 0;
    vector<vector<int>> colors(n + 1);
    while (cnt < r) {
      if (!find[arr[idx]]) {
        colors[arr[idx]].push_back(idx);
        if (colors[arr[idx]].size() == 2) {
          ans[arr[idx]] = {colors[arr[idx]][0], colors[arr[idx]][1]};
          find[arr[idx]] = true;
          ++f;
          cnt++;
        }
      }
      idx++;
    }
  }
  for (auto& a : ans) {
    cout << a.first << " " << a.second << "\n";
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.sync_with_stdio(false);
  cout.tie(0);
  solve();
  return 0;
}
