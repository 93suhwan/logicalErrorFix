#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC target("avx")
using namespace std;
const long long maxn = 4e5 + 5;
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
long long n;
int dp[1 << 20][2];
char s[20][maxn];
int f[maxn], mi[maxn];
int trs[maxn][20];
int cnt[maxn];
inline void upd(int &x, int y) { return x = x >= y ? x : y, void(); }
int main() {
  clock_t st = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> (s[i] + 1);
    int sum = 0;
    long long len = strlen(s[i] + 1);
    for (int j = 1; j <= len; j++) {
      sum += (s[i][j] == '(' ? 1 : -1);
      mi[i] = max(mi[i], -sum);
    }
    f[i] = sum;
    tot += len;
  }
  for (int i = 0; i < n; i++) {
    int len = strlen(s[i] + 1);
    int sum = (s[i][1] == '(' ? 1 : -1), now = 1;
    for (int j = 0; j <= tot - len; j++) {
      while (now <= len && sum + j >= 0) {
        if (sum <= 0) cnt[-sum]++;
        now++;
        sum += (s[i][now] == '(' ? 1 : -1);
      }
      trs[j][i] = cnt[j];
    }
    sum = 0;
    for (int j = 1; j <= len; j++) {
      sum += (s[i][j] == '(' ? 1 : -1);
      if (sum <= 0) cnt[-sum] = 0;
    }
  }
  memset(dp, -0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1) sum += f[j];
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) continue;
      upd(dp[i ^ (1 << j)][1], dp[i][1]);
      if (dp[i][0] >= 0)
        upd(dp[i ^ (1 << j)][sum < mi[j]], dp[i][0] + trs[sum][j]);
    }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]) << endl;
  return 0;
}
