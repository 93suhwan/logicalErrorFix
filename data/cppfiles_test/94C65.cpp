#include <bits/stdc++.h>
using namespace std;
const long long N = 15;
long long t, n, k;
long long a[N];
long long b[N];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
signed main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = qpow(10, a[i]);
    }
    long long i, ans = 0;
    for (i = 2; i <= n; i++) {
      long long cnt = (b[i] - b[i - 1]) / b[i - 1];
      if (k < cnt) break;
      k -= cnt;
      ans += cnt * b[i - 1];
    }
    ans += (k + 1) * b[i - 1];
    cout << ans << endl;
  }
}
