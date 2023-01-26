#include <bits/stdc++.h>
using namespace std;
void solve(int tc) {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 1; i <= n; i++) {
    int k, mx = -1e9;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      mx = max(mx, x - (j - 1) + 1);
    }
    a.push_back(make_pair(mx, k));
  }
  sort(a.begin(), a.end());
  int ans = 0, cur = 0;
  for (auto [x, k] : a) {
    if (cur < x) {
      ans += x - cur;
      cur = x;
    }
    cur += k;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tc = 0;
  cin >> t;
  while (t--) solve(++tc);
}
