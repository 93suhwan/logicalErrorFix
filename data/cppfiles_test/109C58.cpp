#include <bits/stdc++.h>
using namespace std;
long long T, n, w, ans, c[9], fc[200005], iv[200005];
char a[200005], b[200005];
void adt(long long &x, long long y) {
  x = ((x + y > 998244353) ? (x + y - 998244353) : (x + y));
}
long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; x = x * x % 998244353, y >>= 1)
    if (y & 1) ans = ans * x % 998244353;
  return ans;
}
long long C(long long x, long long y) {
  return x < y ? 0 : fc[x] * iv[y] % 998244353 * iv[x - y] % 998244353;
}
signed main() {
  cin >> n;
  fc[0] = iv[0] = 1;
  for (long long i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for (long long i = 1; i < 200005; ++i)
    fc[i] = 1ll * fc[i - 1] * i % 998244353;
  iv[200005 - 1] = ksm(fc[200005 - 1], 998244353 - 2);
  for (long long i = 200005 - 2; i >= 0; --i)
    iv[i] = iv[i + 1] * (i + 1) % 998244353;
  for (long long i = 1; i <= n; ++i)
    ++c[(a[i] == 'B') * 3 + (a[i] == '?') * 6 + (b[i] == 'B') +
        (b[i] == '?') * 2];
  if (!c[0] && !c[4])
    adt(ans, 998244353 - ksm(2, c[8]) + (!c[1] && !c[2] && !c[7]) +
                 (!c[3] && !c[5] && !c[6]));
  w = c[4] + c[5] + c[7] + c[8] - c[0];
  if (w < 0) return printf("%d\n", ans), 0;
  adt(ans, C(c[2] + c[5] + c[6] + c[7] + c[8] * 2, w));
  printf("%d\n", ans);
  return 0;
}
