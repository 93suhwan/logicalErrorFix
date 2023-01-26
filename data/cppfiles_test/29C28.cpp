#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x * f;
}
inline void write(register int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
int n, a[300005];
long long ans, sm;
long long bl1[5005], bl2[5005];
long long tr1[300005 * 20], tr2[300005 * 20];
void modify(int x) {
  for (int i = x / 560; i < 560; ++i) ++bl1[i], bl2[i] += x;
  int rb = (x / 560 + 1) * 560;
  for (int i = x; i < rb; ++i) ++tr1[i], tr2[i] += x;
}
long long qry1(int x) { return (x >= 560 ? bl1[x / 560 - 1] : 0) + tr1[x]; }
long long qry2(int x) { return (x >= 560 ? bl2[x / 560 - 1] : 0) + tr2[x]; }
long long rqry1(int l, int r) { return qry1(r) - qry1(l - 1); }
long long rqry2(int l, int r) { return qry2(r) - qry2(l - 1); }
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    ans += sm;
    ans += 1ll * a[i] * (i - 1);
    for (int l = 1, r; l < a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      if (r == a[i]) r = a[i] - 1;
      ans -= rqry2(l, r) * (a[i] / l);
    }
    for (int l = a[i], r = 2 * a[i] - 1, cnt = 1; l <= 300000;
         l += a[i], r += a[i], ++cnt)
      ans -= rqry1(l, min(r, 300000)) * a[i] * cnt;
    modify(a[i]);
    sm += a[i];
    printf("%lld ", ans);
  }
  return 0;
}
