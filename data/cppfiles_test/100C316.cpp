#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n == 1) {
    cout << a[0] << "\n";
  } else {
    long long sum = a[0];
    long long m = a[0];
    for (long long i = 1; i < n; i++) {
      a[i] = a[i] - sum;
      m = max(m, a[i]);
      sum = sum + a[i];
    }
    cout << m << "\n";
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
