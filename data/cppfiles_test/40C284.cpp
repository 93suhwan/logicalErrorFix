#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  for (int i = 1; i < n; i++) {
    b[i] += b[i - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    a[i] += a[i + 1];
  }
  long long int ans = a[1];
  ans = min(ans, b[n - 2]);
  for (int i = 1; i < n - 1; i++) {
    long long int a1 = b[i - 1];
    long long int a2 = a[i + 1];
    long long int p = max(a1, a2);
    ans = min(ans, p);
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
