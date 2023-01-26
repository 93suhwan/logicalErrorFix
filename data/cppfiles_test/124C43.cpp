#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
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
namespace rndom {
mt19937 mtrnd(std::chrono::system_clock::now().time_since_epoch().count());
long long rnd(long long x) { return mtrnd() % x; }
long long rndrg(long long l, long long r) { return l + rnd(r - l + 1); }
template <class T>
void rndshfl(T *pt, T *ed) {
  long long len = ed - pt;
  for (int i = 0; i < len; i++) swap(pt[i], pt[rnd(len)]);
  return;
}
}  // namespace rndom
using namespace IO;
using namespace rndom;
const int mod = 1e9 + 7;
int T;
int n;
char s[maxn], t[maxn];
int f[2005][4005], g[2005][4005];
inline void upd(int &x, int y) {
  return x = x + y >= mod ? x + y - mod : x + y, void();
}
inline int ab(int x) { return x < 0 ? -x : x; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> (s + 1) >> (t + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] != '?') {
        s[i] = (char)(((s[i] - '0') ^ (i & 1)) + '0');
      }
      if (t[i] != '?') {
        t[i] = (char)(((t[i] - '0') ^ (i & 1)) + '0');
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n + n; j++) {
        f[i][j] = g[i][j] = 0;
      }
    }
    g[0][n] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n + n; j++) {
        if (s[i + 1] != '1' && t[i + 1] != '1') {
          upd(f[i + 1][j], (f[i][j] + 1ll * abs(j - n) * g[i][j] % mod) % mod);
          upd(g[i + 1][j], g[i][j]);
        }
        if (s[i + 1] != '0' && t[i + 1] != '0') {
          upd(f[i + 1][j], (f[i][j] + 1ll * abs(j - n) * g[i][j] % mod) % mod);
          upd(g[i + 1][j], g[i][j]);
        }
        if (s[i + 1] != '1' && t[i + 1] != '0') {
          upd(f[i + 1][j - 1],
              (f[i][j] + 1ll * abs(j - 1 - n) * g[i][j] % mod) % mod);
          upd(g[i + 1][j - 1], g[i][j]);
        }
        if (s[i + 1] != '0' && t[i + 1] != '1') {
          upd(f[i + 1][j + 1],
              (f[i][j] + 1ll * abs(j + 1 - n) * g[i][j] % mod) % mod);
          upd(g[i + 1][j + 1], g[i][j]);
        }
      }
    }
    cout << f[n][n] << '\n';
  }
  cout.flush();
  return 0;
}
