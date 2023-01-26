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
long long a[1000003], b[1000003];
char s[1000003], t[1000003];
void print(long long x) {
  if (x > 0)
    printf("%lld L\n", x);
  else
    printf("%lld R\n", -x);
  return;
}
long long L = 1, R, rev = 0;
long long gpre(long long x) {
  if (rev)
    return b[R] - b[R - x];
  else
    return b[L + x - 1] - b[L - 1];
}
long long ans[1000003];
long long cur = 0;
void RED() {
  if (rev)
    ans[cur--] = a[L], ++L;
  else
    ans[cur--] = a[R], --R;
}
signed main() {
  long long n = read();
  R = n;
  cur = n;
  for (long long i = 1; i <= n; ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  scanf("%s", s + 1);
  if (s[n] == 'L') {
    for (long long i = (n + 1) & 1; i <= n; i += 2) a[i] = -a[i];
    for (long long i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i];
    for (long long i = n - 1; i >= 1; --i, RED())
      if ((s[i] == 'L') != (gpre(i) > 0)) {
        rev ^= 1;
      }
  } else {
    for (long long i = n & 1; i <= n; i += 2) a[i] = -a[i];
    for (long long i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i];
    for (long long i = n - 1; i >= 1; --i, RED())
      if ((s[i] == 'L') != (gpre(i) > 0)) {
        rev ^= 1;
      }
  }
  ans[1] = a[L];
  for (long long i = 1; i <= n; ++i) print(ans[i]);
  return 0;
}
