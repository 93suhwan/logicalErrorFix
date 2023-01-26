#include <bits/stdc++.h>
using namespace std;
int inf;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T, class T2>
int chkmin(T &a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
template <class T, class T2>
int chkmax(T &a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T, class T2>
T mmin(T a, T2 b) {
  return a < b ? a : b;
}
template <class T, class T2>
T mmax(T a, T2 b) {
  return a > b ? a : b;
}
template <class T>
T aabs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
int dcmp(T a, T b) {
  return a > b;
}
template <int *a>
int cmp_a(int first, int second) {
  return a[first] < a[second];
}
template <class T>
bool sort2(T &a, T &b) {
  return a > b ? swap(a, b), 1 : 0;
}
template <class T, class... T2>
T mmin(T a, T2... b) {
  return mmin(a, mmin(b...));
}
template <class T, class... T2>
T mmax(T a, T2... b) {
  return mmax(a, mmax(b...));
}
struct __INIT__ {
  __INIT__() {
    fill((unsigned char *)&inf, (unsigned char *)&inf + sizeof(inf), 0x3f);
  }
} __INIT___;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char first) {
  *oS++ = first;
  if (oS == oT) flush();
}
template <typename A>
inline bool read(A &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(char &first) {
  while ((first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)) == ' ' ||
         first == '\n' || first == '\r')
    ;
  return first != EOF;
}
inline bool read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    ;
  if (*first == EOF) return 0;
  while (!(*first == '\n' || *first == ' ' || *first == '\r' || *first == EOF))
    *(++first) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                           : *iS++);
  *first = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &first, B &...second) {
  return read(first) && read(second...);
}
template <typename A>
inline bool write(A first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char first) {
  putc(first);
  return 0;
}
inline bool write(const char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
inline bool write(char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A first, B... second) {
  return write(first) || write(second...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
const int p = 1000000007;
struct Z {
  unsigned first;
  Z() {}
  Z(unsigned a) { first = a; }
};
inline unsigned modp(const unsigned first) {
  return first < p ? first : first - p;
}
inline Z operator+(const Z x1, const Z x2) { return modp(x1.first + x2.first); }
inline Z operator-(const Z x1, const Z x2) {
  return modp(x1.first + p - x2.first);
}
inline Z operator-(const Z first) { return first.first ? p - first.first : 0; }
inline Z operator*(const Z x1, const Z x2) {
  return static_cast<unsigned long long>(x1.first) * x2.first % p;
}
void exgcd(int a, int b, int &first, int &second) {
  if (!b) {
    first = 1;
    second = 0;
    return;
  }
  exgcd(b, a % b, second, first);
  second -= (a / b) * first;
}
inline Z Inv(const Z a) {
  int first, second;
  exgcd(p, a.first, first, second);
  return second < 0 ? second += p : second;
}
inline Z operator/(const Z x1, const Z x2) { return x1 * Inv(x2); }
inline Z &operator++(Z &x1) {
  x1.first == p - 1 ? x1.first = 0 : ++x1.first;
  return x1;
}
inline Z &operator--(Z &x1) {
  x1.first ? --x1.first : x1.first = p - 1;
  return x1;
}
inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }
inline Z &operator/=(Z &x1, const Z x2) { return x1 = x1 / x2; }
inline Z fpm(Z a, int b) {
  Z c(1);
  for (; b; b >>= 1, a *= a)
    if (b & 1) c *= a;
  return c;
}
namespace run {
char s[2005], t[2005];
Z xf[2005][4005], xg[2005][4005];
int n;
int mx(int first, int second) {
  return first <= n && s[first] != (second ^ 1) + '0';
}
int my(int first, int second) {
  return first <= n && t[first] != (second ^ 1) + '0';
}
bool main() {
  read(n);
  read(s + 1);
  read(t + 1);
  for (int i = 2; i <= n; i += 2) {
    if (s[i] != '?') s[i] ^= 1;
    if (t[i] != '?') t[i] ^= 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = -n; j <= n; ++j) xf[i][j + n] = xg[i][j + n] = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if (mx(1, i) && my(1, j)) {
        xf[1][i - j + n] += 1;
        xg[1][i - j + n] += (i == j ? 0 : p - 1);
      }
  for (int i = 1; i < n; ++i) {
    for (int j = -i; j <= i; ++j)
      if (xf[i][j + n].first || xg[i][j + n].first) {
        for (int first = 0; first < 2; ++first)
          for (int second = 0; second < 2; ++second)
            if (mx(i + 1, first) && my(i + 1, second)) {
              if (first == second)
                xf[i + 1][j + n] += xf[i][j + n],
                    xg[i + 1][j + n] += xg[i][j + n];
              else {
                if (j && (j > 0) != (first > second)) {
                  xf[i + 1][j + first - second + n] += xf[i][j + n];
                  xg[i + 1][j + first - second + n] +=
                      xg[i][j + n] + xf[i][j + n] * (i + 1);
                } else {
                  xf[i + 1][j + first - second + n] += xf[i][j + n];
                  xg[i + 1][j + first - second + n] +=
                      xg[i][j + n] - xf[i][j + n] * (i + 1);
                }
              }
            }
      }
  }
  write(xg[n][0 + n].first, '\n');
  return 0;
}
}  // namespace run
signed main() {
  int t;
  read(t);
  for (; t; --t) {
    run::main();
  }
  return 0;
}
