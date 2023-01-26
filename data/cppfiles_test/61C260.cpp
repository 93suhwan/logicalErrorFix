#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ret = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9')
    ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
  return ret;
}
long long T;
const long long maxn = 2e5 + 5;
long long n;
long long ans;
long long cnta[maxn], cntb[maxn], a[maxn], b[maxn];
signed main() {
  T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; i++) cnta[i] = cntb[i] = 0;
    ans = 0;
    for (long long i = 1; i <= n; i++) {
      cnta[a[i] = read()]++;
      cntb[b[i] = read()]++;
    }
    for (long long i = 1; i <= n; i++)
      ans -= (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
    ans = ans + n * (n - 1) * (n - 2) / 6;
    printf("%lld\n", ans);
  }
  return 0;
}
