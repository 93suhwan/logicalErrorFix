#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long l = 1, r = arr[n - 1], ans = 1;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      vector<long long> ok(n);
      for (long long i = 0; i < n; i++) {
        ok[i] = arr[i];
      }
      long long pp = 0;
      for (long long i = n - 1; i >= 2; i--) {
        long long tt = min(arr[i], ok[i] - mid);
        if (tt < 0) {
          pp++;
          break;
        } else {
          tt /= 3;
          ok[i] -= tt * 3;
          ok[i - 1] += tt;
          ok[i - 2] += tt * 2;
        }
      }
      for (long long i = 0; i < n; i++) {
        if (ok[i] < mid) {
          pp++;
          break;
        }
      }
      if (pp != 0) {
        r = mid - 1;
      } else {
        ans = max(ans, mid);
        l = mid + 1;
      }
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
