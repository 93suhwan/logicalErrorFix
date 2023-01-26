#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long fpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
long long n, q, a[200005], qzh[200005], qzh2[200005];
long long bas, iv2, iv6;
int main() {
  srand(time(0));
  bas = 0;
  iv2 = fpow(2, mod - 2), iv6 = fpow(6, mod - 2);
  scanf("%lld%lld", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    qzh[i] = (qzh[i - 1] + fpow(a[i] + bas, 2)) % mod;
    qzh2[i] = (qzh2[i - 1] + a[i]) % mod;
  }
  for (int i = 1, l, r; i <= q; i++) {
    long long d, st, m, sum;
    scanf("%d%d%lld", &l, &r, &d);
    m = r - l + 1;
    st = ((qzh2[r] - qzh2[l - 1]) - (m - 1) * m % mod * d % mod * iv2 % mod +
          mod) *
         fpow(m, mod - 2) % mod;
    sum =
        (st * st % mod * m % mod +
         d * d % mod * (m - 1) % mod * m % mod * (2 * m - 1) % mod * iv6 % mod +
         st * d % mod * m % mod * (m - 1) % mod) %
        mod;
    if (sum == qzh[r] - qzh[l - 1])
      printf("YES\n");
    else
      printf("NO\n");
  }
}
