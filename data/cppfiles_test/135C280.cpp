#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (k == 0) {
    cout << sum << "\n";
    return;
  }
  sum = 0;
  sort(a.begin(), a.end());
  for (long long i = 0; i < n - 2 * k; i++) {
    sum += a[i];
  }
  for (long long i = n - 2 * k; i < n - k; i++) {
    sum += a[i] / a[i + k];
  }
  cout << sum << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
