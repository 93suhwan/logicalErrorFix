#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<bool> vis(n + 1, false);
  int idx = 0;
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      int c = idx + j;
      if (vis[c % n]) continue;
      if (arr[c % n] == i) {
        if (k != 0) ans.push_back({i, k});
        vis[c % n] = 1;
        idx = c + 1;
        break;
      }
      k++;
    }
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
