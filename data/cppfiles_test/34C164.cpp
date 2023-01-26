#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = INT_MIN;
  cin >> n >> k;
  vector<long long> arr(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> arr[i];
  }
  for (long long i = max(n - 300, 1LL); i < n + 1; i++) {
    for (long long j = i + 1; j < n + 1; j++) {
      ans = max(ans, i * j - k * (arr[i] | arr[j]));
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
