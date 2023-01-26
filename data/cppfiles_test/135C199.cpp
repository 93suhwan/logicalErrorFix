#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    long long a[n];
    long long p = n, q = k, z = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    long long sum1 = sum;
    long long sum2 = sum;
    long long sum3 = sum;
    long long x = k, m = n;
    sort(a, a + n);
    while (x--) {
      sum3 = sum3 + (a[m - k - 1] / a[m - 1]);
      sum3 = sum3 - a[m - k - 1] - a[m - 1];
      m--;
    }
    while (q--) {
      sum1 = sum1 + (a[z] / a[p - 1]);
      sum1 = sum1 - a[z] - a[p - 1];
      p--;
      z++;
    }
    while (k--) {
      sum2 = sum2 + (a[n - 2] / a[n - 1]);
      sum2 = sum2 - a[n - 2] - a[n - 1];
      n -= 2;
    }
    long long ans = min(sum1, sum2);
    ans = min(ans, sum3);
    cout << ans << endl;
  }
  return 0;
}
