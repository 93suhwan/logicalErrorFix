#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = INT_MIN;
  cin >> n >> k;
  long long arr[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> arr[i];
  for (int i = max(n - 200, 1LL); i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      ans = max(ans, i * j - k * (arr[i] | arr[j]));
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
