#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  long long start = max(1LL, n - 500);
  long long ans = LLONG_MIN;
  for (long long i = start; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      ans = max(ans, 1LL * (i * j) - (k * (arr[i] | arr[j])));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int i, j, k, l, m, n, t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
