#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  long long i = 0;
  for (; i < n - 2 * k; i++) ans += a[i];
  long long j = i + k;
  while (j < n) {
    ans += a[i] / a[j];
    i++;
    j++;
  }
  cout << ans << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
