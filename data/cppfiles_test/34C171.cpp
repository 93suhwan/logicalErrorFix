#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = n * n - n - k * (a[n - 1] | a[n - 2]);
  if (n * n - n * (1 + 2 * k) <= 0) {
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
      }
    }
    cout << ans << endl;
    return;
  }
  for (long long i = 0; i < n - 1; i++) {
    long long p = (n * n - n * (1 + 2 * k)) / (i + 1);
    if (p <= i) p = i + 1;
    for (long long j = p; j < n; j++) {
      long long val = (i + 1) * (j + 1) - k * (a[i] | a[j]);
      ans = max(ans, val);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
