#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool f = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = 1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
const long long mod = 998244353;
inline long long Add(long long x, long long y) {
  x += y;
  return (x < mod) ? x : x - mod;
}
inline long long Dec(long long x, long long y) {
  x -= y;
  return (x < 0) ? x + mod : x;
}
inline long long Mul(long long x, long long y) { return x * y % mod; }
inline long long Pow(long long x, long long y) {
  y %= (mod - 1);
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
const int N = 5e5 + 5;
int n, a[N];
long long s[N], f[N];
int st[N], top;
int main() {
  n = read();
  for (int i = (1), end_i = (n); i <= end_i; i++) a[i] = read();
  s[0] = 1;
  f[0] = 1;
  long long now = 0;
  for (int i = (1), end_i = (n); i <= end_i; i++) {
    for (; top && a[st[top]] > a[i]; top--)
      now = Dec(now, Dec(s[st[top] - 1], st[top - 1] ? s[st[top - 1] - 1] : 0) *
                         a[st[top]] % mod);
    now = Add(now, Dec(s[i - 1], st[top] ? s[st[top] - 1] : 0) * a[i] % mod);
    st[++top] = i;
    f[i] = (mod - now) % mod;
    s[i] = Add(s[i - 1], f[i]);
  }
  printf("%lld\n", f[n] * Pow(mod - 1, n) % mod);
  return 0;
}
