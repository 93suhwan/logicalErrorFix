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
int n;
char s[maxn];
int pcnt[25][26];
int w[1 << 23];
void upd(int &x, int y) {
  return x = x + y >= mod ? x + y - mod : x + y, void();
}
long long ans = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> (s + 1);
    int len = strlen(s + 1);
    for (int j = 1; j <= len; j++) {
      pcnt[i][s[j] - 'a']++;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    w[i] = 1;
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      int mi = 1e9;
      for (int k = 0; k < n; k++) {
        if ((i >> k) & 1) {
          mi = min(mi, pcnt[k][j]);
        }
      }
      w[i] = 1ll * (mi + 1) * w[i] % mod;
    }
    for (int j = 0; j < n; j++) cnt += ((i >> j) & 1);
    if (cnt % 2 == 0) w[i] = (mod - w[i]) % mod;
  }
  int len = (1 << n);
  for (int i = 1; i <= n; i++) {
    int p = (1 << i);
    int hf = (p >> 1);
    for (int j = 0; j + p <= len; j += p) {
      for (int k = j; k < j + hf; k++) {
        upd(w[k + hf], w[k]);
      }
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    int cnt = 0;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        cnt++;
        sum += j + 1;
      }
    }
    long long pans = 1ll * cnt * sum * w[i];
    ans ^= pans;
  }
  cout << ans << endl;
  return 0;
}
