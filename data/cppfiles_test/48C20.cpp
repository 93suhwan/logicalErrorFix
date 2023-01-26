#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char s;
  while ((s = getchar()) < '0' || s > '9')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s ^ '0'), s = getchar();
  return x * f;
}
const long long maxn = 100005;
long long n, q, a[maxn];
struct node {
  long long l, r, minn, maxx;
} t[maxn << 2];
void build(long long p, long long l, long long r) {
  t[p].l = l, t[p].r = r;
  if (l == r) {
    t[p].maxx = a[l], t[p].minn = a[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  t[p].maxx = max(t[p << 1].maxx, t[p << 1 | 1].maxx);
  t[p].minn = min(t[p << 1].minn, t[p << 1 | 1].minn);
}
long long getmn(long long p, long long l, long long r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].minn;
  }
  long long mid = (t[p].l + t[p].r) >> 1;
  long long ans = 91000000000000ll;
  if (l <= mid) ans = min(ans, getmn(p << 1, l, r));
  if (mid < r) ans = min(ans, getmn(p << 1 | 1, l, r));
  return ans;
}
long long getmx(long long p, long long l, long long r) {
  if (l <= t[p].l && t[p].r <= r) {
    return t[p].maxx;
  }
  long long mid = (t[p].l + t[p].r) >> 1;
  long long ans = -91000000000000ll;
  if (l <= mid) ans = max(ans, getmx(p << 1, l, r));
  if (mid < r) ans = max(ans, getmx(p << 1 | 1, l, r));
  return ans;
}
signed main() {
  n = read(), q = read();
  for (register long long i = 1; i <= n; ++i) a[i] = -read();
  for (register long long i = 1; i <= n; ++i) a[i] += read();
  for (register long long i = 1; i <= n; ++i) a[i] += a[i - 1];
  build(1, 1, n);
  for (long long i = 1; i <= q; ++i) {
    long long l = read(), r = read();
    if (a[r] - a[l - 1] != 0 || getmn(1, l, r) - a[l - 1] < 0) {
      puts("-1");
      continue;
    }
    printf("%lld\n", getmx(1, l, r) - a[l - 1]);
  }
  return 0;
}
