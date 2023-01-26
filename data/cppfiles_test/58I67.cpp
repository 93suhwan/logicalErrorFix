#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int s = 0;
  int x = 1;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
const int N = 2e5 + 55;
const int mod = 998244353;
int T, n, m, x, y, cd[N], fac[N], ifac[N];
int pd[N], ans;
int summ[N * 4];
int ksm(int x, int k) {
  int base = 1;
  while (k) {
    if (k & 1) base = 1ll * base * x % mod;
    k >>= 1;
    x = 1ll * x * x % mod;
  }
  return base;
}
int C(int n, int m) {
  if (n < m) return 0;
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void add(int u, int l, int r, int x, int k) {
  if (l == r) {
    summ[u] += k;
    return;
  }
  if (x <= ((l + r) >> 1))
    add((u << 1), l, ((l + r) >> 1), x, k);
  else
    add((u << 1 | 1), ((l + r) >> 1) + 1, r, x, k);
  summ[u] = summ[(u << 1)] + summ[(u << 1 | 1)];
}
int ask(int u, int l, int r, int x) {
  if (l == r) return l;
  if (summ[(u << 1)] >= x)
    return ask((u << 1), l, ((l + r) >> 1), x);
  else
    return ask((u << 1 | 1), ((l + r) >> 1) + 1, r, x - summ[(u << 1)]);
}
void build(int u, int l, int r) {
  if (l == r) {
    summ[u] = 1;
    return;
  }
  build((u << 1), l, ((l + r) >> 1));
  build((u << 1 | 1), ((l + r) >> 1) + 1, r);
  summ[u] = summ[(u << 1)] + summ[(u << 1 | 1)];
}
void clear(int u, int l, int r) {
  summ[u] = 0;
  if (l == r) {
    pd[l] = 0;
    return;
  }
  clear((u << 1), l, ((l + r) >> 1));
  clear((u << 1 | 1), ((l + r) >> 1) + 1, r);
}
void solve() {
  ans = 0;
  build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    if (!cd[i]) {
      add(1, 1, n, ask(1, 1, n, i), -1);
    } else {
      x = ask(1, 1, n, cd[i]);
      y = ask(1, 1, n, cd[i] + 1);
      add(1, 1, n, x, -1);
      if (!pd[y]) ans++;
      pd[y] = 1;
    }
    cd[i] = 0;
  }
  clear(1, 1, n);
  cout << C(2 * n - 1 - ans, n) << endl;
}
int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= N - 5; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[N - 5] = ksm(fac[N - 5], mod - 2);
  for (int i = N - 6; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  cin >> T;
  while (T--) {
    n = read();
    m = read();
    for (int i = 1; i <= m; i++) x = read(), y = read(), cd[x] = y;
    solve();
  }
  return 0;
}
