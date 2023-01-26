#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const long long N = 2e6 + 5;
const long long M = 70;
const long long SZ = 450;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long n, d, ans;
struct P {
  long long s, a;
} a[N];
bool cmp(P x, P y) {
  return max(x.s, x.a) == max(y.s, y.a) ? x.s < y.s
                                        : max(x.s, x.a) < max(y.s, y.a);
}
signed main() {
  n = read();
  d = read();
  for (long long i = 1; i <= n; i++) a[i].s = read(), a[i].a = read();
  sort(a + 1, a + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    if (a[i].s >= d) ans++, d = max(d, a[i].a);
  }
  cout << ans << "\n";
}
