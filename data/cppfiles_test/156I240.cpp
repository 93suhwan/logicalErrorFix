#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    long long a[n], i;
    long long sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    long long c = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == a[0]) c++;
    }
    long long ans = 1e12;
    if (n == 1) {
      if (a[0] > k)
        ans = a[0] - k;
      else
        ans = 0;
      cout << ans << "\n";
      continue;
    }
    if (sum <= k) {
      cout << 0 << "\n";
      continue;
    }
    long long low = INT_MIN, high = a[0];
    while (low <= high) {
      long long mid = (low + high) / 2;
      long long q = sum - k;
      long long p = 0;
      if (mid < a[0]) {
        p = a[0] - mid;
        q -= (a[0] - mid);
      }
      for (long long i = n - 1; i >= 1; i--) {
        if (q <= 0) break;
        q -= (a[i] - mid);
        p++;
        if (q <= 0) break;
      }
      if (q <= 0) {
        ans = min(ans, p);
        low = mid + 1;
      } else
        high = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
