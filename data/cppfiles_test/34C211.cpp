#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long mx = INT_MIN;
  for (long long i = max(n - 2 * k, 1ll * 1); i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      long long val = a[i] | a[j];
      mx = max(mx, i * j - k * val);
    }
  }
  cout << mx << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
