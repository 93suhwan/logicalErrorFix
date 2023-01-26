#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long maxm = 1e3 + 5;
namespace IO {
const int SIZE = (1 << 20) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
char _st[55];
int _qr = 0;
inline char gc() {
  return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
}
inline void qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &...ls) {
  T1 __ = 0, ___ = 1;
  char ch;
  while (!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
  do {
    __ = (__ << 1) + (__ << 3) + (ch ^ 48);
  } while (isdigit(ch = gc()));
  __ *= ___;
  IEE = __;
  qread(ls...);
  return;
}
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
  return;
}
inline void putc_(char _x) {
  *oS++ = _x;
  if (oS == oT) flush();
}
inline void qwrite() {}
template <class T1, class... T2>
inline void qwrite(T1 IEE, T2... ls) {
  if (!IEE) putc_('0');
  if (IEE < 0) putc_('-'), IEE = -IEE;
  while (IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
  while (_qr) putc_(_st[_qr--]);
  qwrite(ls...);
  return;
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher;
}  // namespace IO
using namespace IO;
const int mod = 998244353;
int n, K;
int b[maxn];
int f[2][2005][2005];
int s[2005][2005];
int fac[2005], ifac[2005];
int qpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  return;
}
inline void upd(int &x, int y) {
  return x = x + y >= mod ? x + y - mod : x + y, void();
}
int ans = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> K;
  for (int i = 1; i <= n; i++) cin >> b[i];
  init();
  f[0][0][0] = 1;
  s[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int cur = i & 1;
    if (i > 1) {
      for (int j = max(0, b[i - 2] - K); j <= min(n, b[i - 2] + K); j++) {
        for (int k = j; k <= n; k++) f[cur][j][k] = 0;
      }
    }
    int L = max(0, b[i] - K), R = min(n, b[i] + K);
    for (int j = L; j <= R && j <= i; j++) {
      for (int k = j; k <= j + i && k <= n; k++) {
        upd(f[cur][j][k], 1ll * f[cur ^ 1][j][k] * k % mod);
        if (k) upd(f[cur][j][k], f[cur ^ 1][j][k - 1]);
        if (j && k)
          upd(f[cur][j][k],
              1ll * s[k - 1][min(b[i - 1] + K, j - 1)] * ifac[k - j] % mod);
      }
    }
    for (int j = max(0, b[i - 1] - K); j <= min(n, b[i - 1] + K); j++) {
      for (int k = j; k <= n; k++) s[k][j] = 0;
    }
    for (int j = L; j <= i; j++) {
      s[j][L] = 1ll * f[cur][L][j] * fac[j - L] % mod;
      for (int k = L + 1; k <= R; k++) {
        s[j][k] = s[j][k - 1];
        if (k <= j) upd(s[j][k], 1ll * f[cur][k][j] * fac[j - k] % mod);
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      upd(ans, 1ll * f[n & 1][i][j] * fac[n - i] % mod * ifac[n - j] % mod);
    }
  }
  cout << ans << endl;
  return 0;
}
