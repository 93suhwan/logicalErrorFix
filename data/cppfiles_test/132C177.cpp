#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
void solve() {
  long long a[7];
  long long maxim = INT_MIN;
  long long n = 7;
  for (long long i = 0; i < 7; i++) {
    cin >> a[i];
    if (a[i] > maxim) {
      maxim = a[i];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      for (long long k = 0; k < n; k++) {
        if (a[i] + a[j] + a[k] == maxim) {
          if (i != j && i != k && j != k) {
            cout << a[i] << " " << a[j] << " " << a[k] << endl;
            return;
          }
        }
      }
    }
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
