#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> prev(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> prev[i];
    mx = max(mx, prev[i]);
  }
  int ans = 0;
  int at = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (prev[i] == mx) break;
    if (prev[i] > at) {
      ans++;
      at = prev[i];
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tc = 1;
  cin >> tc;
  for (int tt = 1; tt <= tc; tt++) {
    solve();
  }
  return 0;
}
