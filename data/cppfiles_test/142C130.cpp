#include <bits/stdc++.h>
using namespace std;
long long t = 1, n, m, k, q, l, r, a[100009], b, c, u, wtf[100009], x, y, z,
          mod = 1e9 + 7;
string s;
vector<long long> v[100009];
struct st {
  long long x, y;
};
bool cmp(const st &a, const st &b) { return a.x < b.x; }
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long qp(long long x, long long y) {
  long long a = 1, b = x;
  while (y) {
    if (y & 1) a = a * b % mod;
    b = b * b % mod, y >>= 1;
  }
  return a;
}
bool judge(long long x) {
  fill(wtf + 1, wtf + m + 1, 0);
  bool qwq = 0;
  for (long long i = 1; i <= n; i += 1) {
    bool fl = 0;
    for (long long j = 1; j <= m; j += 1) {
      if (v[j][i] >= x && wtf[j]) qwq = 1;
      if (v[j][i] >= x) wtf[j] = 1, fl = 1;
    }
    if (!fl) return 0;
  }
  return qwq;
}
int main() {
  t = read();
  while (t--) {
    m = read(), n = read();
    fill(a + 1, a + n + 1, 0);
    for (long long i = 1; i <= m; i += 1) v[i].resize(n + 2);
    for (long long i = 1; i <= m; i += 1)
      for (long long j = 1; j <= n; j += 1) v[i][j] = read();
    if (n > m) {
      for (long long i = 1; i <= m; i += 1)
        for (long long j = 1; j <= n; j += 1) a[j] = max(a[j], v[i][j]);
      printf("%lld\n", *min_element(a + 1, a + n + 1));
    } else {
      long long l = 1, r = 1e9, ans = 0;
      while (l <= r) {
        long long mid = (l + r) >> 1;
        if (judge(mid))
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
