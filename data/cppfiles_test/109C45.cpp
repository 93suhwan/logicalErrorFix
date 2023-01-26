#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353, N = 2e5 + 7;
long long f[N], v[N];
char w[5];
long long pm(long long a, long long n) {
  if (n < 0) return 0;
  long long r = 1;
  while (n) {
    if (n & 1) r = r * a % md;
    a = a * a % md, n >>= 1;
  }
  return r;
}
long long C(long long x, long long y) {
  return f[x] * pm(f[y] * f[x - y] % md, md - 2) % md;
}
int main() {
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % md;
  int al = 0, ar = 0, bl = 0, br = 0, n, cl = 0, cr = 0, cs = 0, ok = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", w);
    if (w[0] == w[1] && w[0] == '?') cs++;
    if (w[0] == w[1] && w[0] != '?') ok = 0;
    if (w[0] == 'W')
      al++;
    else if (w[0] == '?')
      cl++;
    else
      bl++;
    if (w[1] == 'W')
      ar++;
    else if (w[1] == '?')
      cr++;
    else
      br++;
  }
  long long ans;
  int k = 1;
  if (al + br != 0 && ar + bl != 0) k = 0;
  ans = (pm(2, cs) - k) * ok * -1 + md;
  if (cs == n) ans = -1 * (pm(2, cs) - 2) * ok + md;
  if (n == 1) ans = 0;
  for (int i = 0; i <= cl; i++)
    if (al + i >= br && al + i - br <= cr)
      ans = (ans + C(cl, i) * C(cr, al + i - br)) % md;
  printf("%lld", ans % md);
  return 0;
}
