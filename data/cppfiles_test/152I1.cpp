#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, a[1005000], b[2005000], sb, x, y, res;
pair<int, int> p[2005000];
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline long long read() {
  char c =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    f ^= !(c ^ 45);
  for (; isdigit(c);
       c = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++))
    x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  t = read();
  while (t--) {
    n = read();
    for (i = 1; i <= n; i++) {
      a[i] = read();
      b[a[i] + n] = i;
      b[n + 1 - a[i]] = i;
      b[a[i] + n + n + n] = i;
      b[n + 1 - a[i] + n + n] = i;
    }
    res = 0;
    for (i = 1; i <= n + n + n + n + 5; i++) p[i] = {1e9, 1e9};
    for (i = 1; i <= n + n + n + n; i++) {
      x = upper_bound(p + 1, p + n + n + 5, make_pair(b[i], -i)) - p;
      if (b[i] != p[x].first) p[x] = {b[i], -i};
    }
    for (i = 1;; i++) {
      auto [x, y] = p[i];
      if (x > n) break;
      res++;
      y = -y;
      if (y <= n) {
        a[x] = -a[x];
      }
      if (y > (n + n) && y <= (n + n + n)) {
        a[x] = -a[x];
      }
    }
    if (res < n) {
      puts("NO");
    } else {
      puts("YES");
      for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
      }
      puts("");
    }
  }
}
