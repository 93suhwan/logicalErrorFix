#include <bits/stdc++.h>
using namespace std;
long long a[5007], b[5007];
long long pre[5007], back[5007];
long long ksm(long long base, long long p) {
  long long r = 1;
  while (p > 0) {
    if (p & 1) {
      r = r * base;
    }
    p >>= 1;
    base = (base * base);
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      a[i] = ksm(10, x);
      b[i] = x;
    }
    long long ans = 0;
    long long t = m + 1;
    for (long long i = 1; i < n; i++) {
      long long z = b[i + 1] - b[i];
      long long q = ksm(10, z) - 1;
      if (t - q >= 0) {
        t = t - q;
        ans += q * a[i];
      } else {
        ans += t * a[i];
        t = 0;
        break;
      }
    }
    if (t != 0) ans += t * a[n];
    cout << ans << endl;
  }
  return 0;
}
