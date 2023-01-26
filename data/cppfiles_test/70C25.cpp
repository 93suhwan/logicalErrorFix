#include <bits/stdc++.h>
const int N = 2e5 + 10, B = 51, mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void upd(int &a, int b) { a = a + b >= mod ? a + b - mod : a + b; }
inline int power(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1LL * a * a % mod)
    if (b & 1) res = 1LL * res * a % mod;
  return res;
}
int a[N], b[N], c[N], d[N], comb[B][B], s[N][B];
inline int calc(int a, int d, int l, int k) {
  if (a == 0) a = d, --l;
  int ans = 0, x = 1LL * d * power(a, mod - 2) % mod;
  for (int i = 0, w = power(a, k); i <= k; ++i, w = 1LL * w * x % mod)
    upd(ans, 1LL * comb[k][i] * w % mod * s[l - 1][i] % mod);
  return ans;
}
int main() {
  int n = read(), q = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    b[i] = add(b[i - 1], a[i]);
    c[i] = add(c[i - 1], power(a[i], 43));
    d[i] = add(d[i - 1], power(a[i], 42));
  }
  for (int i = 0; i <= B - 1; comb[i][0] = 1, ++i)
    for (int j = 1; j <= B - 1; ++j)
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
  s[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0, w = 1; j < B; ++j, w = 1LL * w * i % mod)
      s[i][j] = add(s[i - 1][j], w);
  for (int T = 1; T <= q; ++T) {
    int l = read(), r = read(), d = read();
    int s = add(b[r], mod - b[l - 1]), len = r - l + 1;
    int a = 1LL * add(mod - 1LL * len * (len - 1) / 2 % mod * d % mod, s) *
            power(len, mod - 2) % mod;
    puts(calc(a, d, len, 43) == add(c[r], mod - c[l - 1]) &&
                 calc(a, d, len, 42) == add(::d[r], mod - ::d[l - 1])
             ? "Yes"
             : "No");
  }
  return 0;
}
