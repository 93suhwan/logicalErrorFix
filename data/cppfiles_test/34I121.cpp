#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = INT_MIN;
  cin >> n >> k;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n - 1; i++) {
    long long p = (i + 1) * (i + 2) - k * (arr[i] | arr[i + 1]);
    ans = max(p, ans);
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
