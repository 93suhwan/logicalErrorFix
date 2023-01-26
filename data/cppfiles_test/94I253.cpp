#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a[n], atmax[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long notes = 0, sum = 0;
  for (long long i = 0; i < n - 1; i++) {
    long long v1 = pow(10, a[i]);
    long long v2 = pow(10, a[i + 1]);
    long long val = v2 / v1 - 1;
    atmax[i] = val;
  }
  for (long long i = 0; i < n; i++) {
    if (notes + atmax[i] <= k) {
      long long val = pow(10, a[i]);
      sum += (val * atmax[i]);
      notes += atmax[i];
    } else {
      long long left = k - notes + 1;
      long long val = pow(10, a[i]);
      sum += (val * left);
      break;
    }
  }
  cout << sum << '\n';
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
