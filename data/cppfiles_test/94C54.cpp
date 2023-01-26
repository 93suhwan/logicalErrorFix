#include <bits/stdc++.h>
using namespace std;
const long long maxn = 11;
long long a[maxn];
long long b[maxn];
inline long long qpow(long long x, long long y) {
  long long res(1);
  while (y) {
    if (y & 1) res = 1ll * res * x;
    x = 1ll * x * x;
    y >>= 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];
    long long now = 0;
    for (long long i = 2; i <= n; i++) {
      long long tmp = qpow(10, b[i]) - 1;
      if (k > tmp) {
        k -= tmp;
        now += tmp * qpow(10, a[i - 1]);
      } else {
        now += k * qpow(10, a[i - 1]);
        k = 0;
        break;
      }
    }
    if (k > 0) {
      now += k * qpow(10, a[n]);
    }
    cout << now << "\n";
  }
}
