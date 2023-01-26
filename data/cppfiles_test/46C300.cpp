#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch;
  bool ok;
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
const long long maxn = 2e5 + 10, mod = 1e9 + 7;
long long add(long long a, long long b) {
  return a + b >= mod ? a + b - mod : a + b;
}
long long del(long long a, long long b) {
  return a - b < 0 ? a - b + mod : a - b;
}
long long mul(long long a, long long b) { return a * b - a * b / mod * mod; }
long long mi(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
long long T, n, a[maxn], ans, flag;
signed main() {
  read(T);
  while (T--) {
    read(n);
    for (register long long i = 1; i <= n; i++) read(a[i]);
    flag = a[n];
    ans = 0;
    for (register long long i = n; i; i--)
      if (a[i] > flag) flag = a[i], ans++;
    printf("%lld\n", ans);
  }
}
