#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int ar[n];
  for (int i = 0; i < (n); i++) cin >> ar[i];
  long long int ans = 0;
  for (int i = 1; i < n; i++) {
    ans = max(ans, ar[i] * ar[i - 1]);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
