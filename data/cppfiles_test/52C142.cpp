#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    double ans = 0;
    long long a[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    ans += a[n - 1];
    ans += (double)(sum - a[n - 1]) / (n - 1);
    cout << setprecision(20) << ans;
    cout << "\n";
  }
}
