#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int b[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++) {
      scanf("%d", &x);
      if (x != 0) b[++tot] = x;
    }
    sort(b + 1, b + 1 + tot);
    long long ans = 0, xx = 0x7fffffffffffffff;
    int p = upper_bound(b + 1, b + 1 + tot, 0) - b;
    int q = p, len;
    if (b[tot] > 0) {
      ans += abs(b[tot]);
      len = tot - p + 1;
      if (len > m) {
        len -= m;
        int tmp = len % m;
        if (tmp) ans += abs(b[p + tmp - 1]) * 2;
        for (int i = p + tmp + m - 1; i < tot; i += m) {
          ans += abs(b[i]) * 2;
        }
      }
      len = p - 1;
      if (len % m != 0) {
        p = p - len % m;
        ans += abs(b[p]) * 2;
      }
      for (int i = p - m; i >= 1; i -= m) {
        ans += abs(b[i]) * 2;
      }
      xx = min(xx, ans);
    }
    long long cnt = 0;
    if (b[1] < 0) {
      cnt += abs(b[1]);
      len = q - 1;
      int idx;
      if (len > m) {
        idx = q - len % m;
        if (len % m) cnt += abs(b[idx]) * 2;
        for (int i = idx - m; i > 1; i -= m) {
          cnt += abs(b[i]) * 2;
        }
      }
      len = tot - q + 1;
      idx = q + len % m - 1;
      if (len % m) cnt += abs(b[idx]) * 2;
      for (int i = idx + m; i <= tot; i += m) {
        cnt += abs(b[i]) * 2;
      }
      xx = min(cnt, xx);
    }
    printf("%lld\n", xx);
    b[tot + 1] = 0;
  }
}
