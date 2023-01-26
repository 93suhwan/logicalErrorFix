#include <bits/stdc++.h>
using namespace std;
int abc;
int rd(int l, int r) { return rand() % (r - l + 1) + l; }
const int mxn = 2e5 + 3, mod = 998244353;
long long por(long long x, int y = mod - 2) {
  long long r = 1;
  for (; y; y >>= 1) {
    if (y & 1) r = r * x % mod;
    x = x * x % mod;
  }
  return r;
}
int n, m, nn, b[mxn][2], d[mxn];
long long jc[mxn * 2], inv[mxn * 2];
struct zZz {
  int a[mxn], tk[mxn], nn;
  void add(int x) {
    tk[++nn] = x;
    for (; x <= n; x += x & -x) ++a[x];
  }
  int ask(int k) {
    int p = 0, z = 0;
    for (int i = 1 << 17; i; i >>= 1) {
      if (p + i > n) continue;
      p += i;
      if (p - z - a[p] >= k)
        p -= i;
      else
        z += a[p];
    }
    return p + 1;
  }
  void clr() {
    while (nn) {
      int x = tk[nn--];
      for (; x <= n; x += x & -x) a[x] = 0;
    }
  }
} ar;
set<int> st;
long long C(int x, int y) { return jc[x] * inv[y] % mod * inv[x - y] % mod; }
int main() {
  n = 2 * mxn - 1;
  jc[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i) jc[i] = jc[i - 1] * i % mod;
  inv[n] = por(jc[n]);
  for (int i = n - 1; i; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
  int ca;
  abc = scanf("%d", &ca);
  while (ca--) {
    ar.clr();
    abc = scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) abc = scanf("%d%d", &b[i][0], &b[i][1]);
    b[m + 1][0] = n + 1;
    nn = 0;
    int ls = n + 1, nm = 0;
    st.clear();
    st.insert(ls);
    d[n + 1] = 0;
    for (int t = m; t; --t) {
      int x = b[t][0], y = b[t][1], k = ar.ask(y), k2 = ar.ask(x + 1),
          xx = b[t + 1][0];
      ar.add(k);
      d[k] = x;
      if (x + 1 != xx) {
        bool oo = 1;
        while (st.size() && *--st.end() > k2) {
          auto it = --st.end();
          k = *it;
          if (k + 1 == ls)
            nm += d[k] != d[k + 1];
          else
            ++nm, nm += !oo || xx - 1 != d[ls];
          oo = 0, ls = k;
          st.erase(it);
        }
        nm += !oo || xx - 1 != d[ls];
        ls = k2, d[k2] = x + 1;
      }
    }
    for (int i = ls - 1; i; --i) nm += d[i] != d[i + 1];
    printf("%lld\n", C(2 * n - nm, n));
  }
  return 0;
}
