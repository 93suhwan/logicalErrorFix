#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 2e5 + _;
const int fbin = (1 << 17) + _;
const int mod = 998244353;
inline int ad(int x, int y) { return x >= mod - y ? x - mod + y : x + y; }
inline int re(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mu(int x, int y) { return (long long)x * y % mod; }
inline int qp(int x, int y) {
  int r = 1;
  while (y) {
    if (y & 1) r = mu(r, x);
    y >>= 1, x = mu(x, x);
  }
  return r;
}
inline int iv(int x) { return qp(x, mod - 2); }
int a[maxn], v[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, s = 0, c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v[i] = 0;
    for (int j = 0; j < 30; j++) {
      c = 0;
      for (int i = 1; i <= n; i++)
        if (a[i] & (1 << j)) c++;
      if (c) {
        s++;
        for (int i = 1; i * i <= c; i++)
          if (c % i == 0) {
            v[i]++;
            if (i * i != c) v[c / i]++;
          }
      }
    }
    for (int i = 1; i <= n; i++)
      if (v[i] == s) printf("%d ", i);
    puts("");
  }
  return 0;
}
