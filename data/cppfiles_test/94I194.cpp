#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long IM = 1e18 + 37;
const long long N = 2e5 + 10;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long &it : a) cin >> it;
    unsigned long long ans = 0;
    long long val = 1;
    for (long long i = 0; i + 1 < n; i++) {
      long long cn = a[i + 1] - a[i];
      long long id = 0;
      while (cn--) {
        id = id * 10 + 9;
      }
      long long mx = id;
      id = min(k, id);
      k -= id;
      val = 1;
      long long now = a[i];
      while (a[i]--) {
        val = val * 10;
      }
      ans += id * val;
      if (k == 0) {
        if (id != mx) {
          ans += val;
        } else {
          if (a[i + 1] == now + 1)
            ans += val * 10;
          else
            ans += val;
        }
        break;
      }
    }
    if (k != 0) {
      val = 1;
      while (a[n - 1]--) val = val * 10;
      ans += (val * (k + 1));
    }
    cout << ans << "\n";
  }
  return 0;
}
