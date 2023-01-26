#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    long long ans = *min_element(v.begin(), v.end());
    long long l = 1, r = 1e10;
    while (l <= r) {
      long long mid = (l + r) / 2;
      bool can = true;
      vector<long long> temp(n), rem(n, 0);
      for (long long i = 0; i < n; i++) {
        temp[i] = v[i];
      }
      for (long long i = n - 1; i >= 2; i--) {
        long long mx = ((temp[i] + rem[i]) - mid) / 3;
        mx = max(mx, 0LL);
        mx = min(mx, temp[i] / 3);
        temp[i] -= 3 * mx;
        rem[i - 1] += mx;
        rem[i - 2] += 2 * mx;
      }
      for (long long i = 0; i < n; i++) {
        if ((temp[i] + rem[i]) < mid) {
          can = false;
        }
      }
      if (can) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << "\n";
  }
}
