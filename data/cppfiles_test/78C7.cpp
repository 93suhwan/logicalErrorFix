#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, nega = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
  return sum * nega;
}
const long long N = 2e5 + 9;
long long T, n, a[N], k;
long long cnt[39], p;
inline long long Gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return Gcd(y, x % y);
}
signed main() {
  T = read();
  for (long long ttt = 1; ttt <= T; ttt++) {
    n = read();
    k = 0;
    p = 0;
    for (long long i = 0; i < 30; i++) cnt[i] = 0;
    for (long long i = 1; i <= n; i++) a[i] = read();
    for (long long i = 1; i <= n; i++)
      for (long long j = 0; j < 30; j++)
        if ((a[i] & (1 << j))) cnt[j]++;
    for (long long i = 0; i < 30; i++) p = max(p, cnt[i]);
    for (long long i = 0; i < 30; i++) p = Gcd(p, cnt[i]), k += cnt[i];
    if (k == 0) {
      for (long long i = 1; i <= n; i++) printf("%lld ", i);
      puts("");
      continue;
    }
    for (long long i = 1; i <= p; i++)
      if (p % i == 0) printf("%lld ", i);
    puts("");
  }
  return 0;
}
