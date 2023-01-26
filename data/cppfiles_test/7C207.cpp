#include <bits/stdc++.h>
using namespace std;
const double pai = acos(-1.0);
const long long maxn = 1e6 + 10;
const long long mod = 998244353;
const double eps = 1e-9;
const long long N = 5e3 + 10;
inline long long read() {
  long long k = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) k = (k << 1) + (k << 3) + c - 48, c = getchar();
  return k * f;
}
long long k, n, m, a[maxn], dis[maxn];
long long gcd(long long a, long long b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
struct node {
  long long l;
  long long r;
  long long data;
} t[maxn << 2];
void pushup(long long p) {
  t[p].data = gcd(t[p << 1].data, t[p << 1 | 1].data);
}
void build(long long p, long long l, long long r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].data = dis[l];
    return;
  }
  long long mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
long long ask(long long p, long long l, long long r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].data;
  }
  long long mid = t[p].l + t[p].r >> 1;
  if (l > mid) return ask(p << 1 | 1, l, r);
  if (r <= mid) return ask(p << 1, l, r);
  return gcd(ask(p << 1, l, r), ask(p << 1 | 1, l, r));
}
signed main() {
  k = read();
  while (k--) {
    n = read();
    for (long long i = 1; i <= n; i++) a[i] = read();
    for (long long i = 1; i <= n - 1; i++) dis[i] = abs(a[i + 1] - a[i]);
    if (n == 1)
      puts("1");
    else {
      build(1, 1, n - 1);
      long long l = 1, ans = 0;
      for (long long r = 1; r < n; r++) {
        while (l <= r && ask(1, l, r) == 1) l++;
        ans = max(ans, 1LL * (r - l + 2));
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
