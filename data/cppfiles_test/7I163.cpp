#include <bits/stdc++.h>
using namespace std;
inline long long r() {
  long long s = 0, k = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * k;
}
long long n, m, a[4000001], tr[4000001], b[1000001], ans;
long long gcd(long long aa, long long bb) {
  if (!bb) return aa;
  return gcd(bb, aa % bb);
}
void build(long long l, long long r, long long bh) {
  if (l == r) {
    tr[bh] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, bh * 2);
  build(mid + 1, r, bh * 2 + 1);
  tr[bh] = gcd(tr[bh * 2], tr[bh * 2 + 1]);
}
long long sum(long long now_l, long long now_r, long long l, long long r,
              long long bh) {
  if (l <= now_l && now_r <= r) return tr[bh];
  if (now_l > r || now_r < l) return 0;
  long long mid = (now_l + now_r) / 2;
  long long x = sum(now_l, mid, l, r, bh * 2),
            y = sum(mid + 1, now_r, l, r, bh * 2 + 1);
  return gcd(max(x, y), min(x, y));
}
signed main() {
  long long t = r();
  while (t--) {
    ans = 0;
    n = r();
    for (long long i = 1; i <= n; i++) {
      b[i] = r();
      a[i - 1] = abs(b[i] - b[i - 1]);
    }
    for (long long i = 0; i <= 4 * n + 5; i++) tr[i] = 0;
    build(1, n - 1, 1);
    long long r = 2;
    for (long long l = 1; l < n; l++) {
      long long x = sum(1, n - 1, l, r - 1, 1);
      while (x > 1 && r <= n) {
        r++;
        if (r > n) break;
        x = sum(1, n - 1, l, r - 1, 1);
      }
      ans = max(ans, r - l);
    }
    cout << ans << endl;
  }
}
