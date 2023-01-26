#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> s;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (auto x : arr) s.push_back(x);
  sort(s.begin(), s.end());
  vector<bool> vis(n + 1, false);
  int idx = 0;
  vector<pair<int, int>> ans;
  int m = 1;
  for (auto i : s) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      int c = idx + j;
      if (vis[c % n]) continue;
      if (arr[c % n] == i) {
        if (k != 0) ans.push_back({m, k});
        vis[c % n] = 1;
        idx = c + 1;
        break;
      }
      k++;
    }
    m++;
  }
  cout << ans.size() << "\n";
  for (auto a : ans) {
    cout << a.first << " " << n << " " << a.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
