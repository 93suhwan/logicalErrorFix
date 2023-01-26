#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 2010;
const int mod = 998244353;
int f[2][N][N], sum[N][N << 1], n, K, b[N], fac[N], ifac[N];
ll qp(ll x, int t) {
  ll res = 1;
  for (; t; t >>= 1, x = x * x % mod)
    if (t & 1) res = res * x % mod;
  return res;
}
void upd(int &x) { x = x + (x >> 31 & mod); }
void init(int l) {
  fac[0] = 1;
  for (int i = (1); i <= (l); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[l] = qp(fac[l], mod - 2);
  for (int i = (l - 1); i >= (0); i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
ll C(int x, int y) {
  return x < 0 || y < 0 || x < y
             ? 0
             : 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
  n = read<int>(), K = read<int>();
  for (int i = (1); i <= (n); i++) b[i] = read<int>();
  init(n);
  int o = 0;
  f[o][0][1] = abs(b[1]) <= K;
  f[o][1][0] = abs(b[1] - 1) <= K;
  for (int i = (2); i <= (n); i++) {
    int lval, rval;
    lval = b[i] - K, rval = b[i] + K;
    chkmax(lval, 0);
    chkmin(rval, n);
    for (int val = (lval); val <= (rval); val++)
      for (int j = (0); j <= (i); j++) f[o ^ 1][val][j] = 0;
    lval = b[i - 1] - K, rval = b[i - 1] + K;
    chkmax(lval, 0);
    chkmin(rval, n);
    for (int val = (lval); val <= (rval); val++) {
      if (val == lval)
        memset(sum[val], 0, sizeof sum[val]);
      else
        memcpy(sum[val], sum[val - 1], sizeof sum[val]);
      for (int j = (0); j <= (i - 1); j++) {
        if (f[o][val][j]) {
          upd(f[o ^ 1][val][j] += 1ll * f[o][val][j] * (val + j) % mod - mod);
          upd(f[o ^ 1][val][j + 1] += f[o][val][j] - mod);
          upd(sum[val][val + j + 1] += 1ll * f[o][val][j] * fac[j] % mod - mod);
        }
      }
    }
    int tlval = lval, trval = rval;
    lval = b[i] - K, rval = b[i] + K;
    chkmax(lval, 1);
    chkmax(lval, tlval + 1);
    chkmin(rval, n);
    for (int val = (lval); val <= (rval); val++)
      for (int j = (0); j <= (i); j++)
        upd(f[o ^ 1][val][j] +=
            1ll * sum[min(val - 1, trval)][val + j] * ifac[j] % mod - mod);
    o ^= 1;
  }
  int ans = 0;
  int lval = b[n] - K, rval = b[n] + K;
  chkmax(lval, 0);
  chkmin(rval, n);
  for (int val = (lval); val <= (rval); val++)
    for (int j = (0); j <= (n); j++)
      upd(ans += 1ll * f[o][val][j] * C(n - val, j) % mod * fac[j] % mod - mod);
  printf("%d\n", ans);
  return 0;
}
