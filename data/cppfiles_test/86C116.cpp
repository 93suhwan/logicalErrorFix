#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const long long p = 998244353;
long long qp(long long x, long long y) {
  long long res = 1;
  for (long long t = x; y; y >>= 1, t = t * t % p)
    if (y & 1) res = res * t % p;
  return res;
}
char s[1000003], t[1000003];
long long a[1000003];
signed main() {
  for (long long T = read(); T--;) {
    long long n = read();
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (long long i = 1; i <= n; ++i) a[i] = (s[i] == '1') + (t[i] == '1');
    long long cur = 0, qwq = 0, ans = 0;
    for (long long i = 1; i <= n; ++i)
      if (a[i] == 1) {
        ans += cur;
        ans += 2;
        cur = 0;
        qwq = 0;
      } else if (a[i] == 0) {
        ans += cur;
        if (qwq)
          qwq = 0, ans += 2, cur = 0;
        else
          cur = 1;
      } else {
        if (cur == 1)
          ans += 2, cur = 0;
        else
          qwq = 1;
      }
    printf("%lld\n", ans + cur);
  }
  return 0;
}
