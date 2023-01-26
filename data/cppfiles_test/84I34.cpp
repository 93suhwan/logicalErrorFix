#include <bits/stdc++.h>
using namespace std;
long long ksm(long long a, long long x) {
  long long ret = 1;
  for (; x; x >>= 1, a = a * a)
    if (x & 1) ret = ret * a;
  return ret;
}
long long rt(long long n, long long t) {
  long long sz = pow(n, 1.0 / t) + 1;
  for (; ksm(sz, t) < n;) sz++;
  for (; ksm(sz - 1, t) >= n;) sz--;
  return sz;
}
long long phi[100000 + 50], g[100000 + 50], notp[100000 + 50], p[100000 + 50];
void prepare() {
  notp[1] = 1;
  phi[1] = 1;
  for (long long i = 2; i <= 100000; i++) {
    if (!notp[i]) p[++p[0]] = i, phi[i] = i - 1;
    for (long long j = 1, x; j <= p[0] && (x = i * p[j]) <= 100000; j++) {
      notp[x] = 1;
      if (i % p[j] == 0) {
        phi[x] = phi[i] * p[j];
        break;
      } else {
        phi[x] = phi[i] * (p[j] - 1);
      }
    }
  }
  g[0] = -1;
  for (long long i = 1; i <= 100000; i++) g[i] = g[i - 1] + 2 * phi[i];
}
long long f(long long l, long long r) {
  long long ans = 0;
  for (long long x = l, y = l; x <= r; x = y + 1) {
    y = r / (r / x);
    ans = ans + (y - x + 1) * g[r / x];
  }
  ans = (ans + (r - l + 1)) / 2;
  return ans;
}
long long T, n, k;
int main() {
  ios_base::sync_with_stdio(false);
  prepare();
  cin >> T;
  for (; T--;) {
    cin >> n >> k;
    if (k >= 20 || (1 << k) > n)
      cout << n << endl;
    else {
      long long l = 1, r = n + 1;
      long long ans = 0;
      for (long long now = k - 1; now >= 1; now--) {
        long long mul = rt(r / l, now + 1);
        long long mid = l * mul;
        ans = ans + f(l, mid - 1);
        l = mid;
      }
      ans = ans + f(l, r - 1);
      cout << ans << '\n';
    }
  }
  return 0;
}
