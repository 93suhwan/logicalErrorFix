#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = INT_MIN;
  long long int a[n + 1];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long int i = 1; i < n; i++) {
    for (long long int j = max({0LL, ans / i, i + 1}); j <= n; j++) {
      long long int x = i * j - (k * (a[i] | a[j]));
      ans = max(ans, x);
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
