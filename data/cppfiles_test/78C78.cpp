#include <bits/stdc++.h>
using namespace std;
namespace Eddd {
inline char sc() {
  return getchar();
  static const int LEN = 100000;
  static char Buf[LEN], *OP = Buf, *ED = Buf;
  if (OP == ED) ED = (OP = Buf) + fread(Buf, 1, LEN, stdin);
  return *OP++;
}
template <class T>
void rd(T &x) {
  static int c, f;
  x = f = 0;
  while (c = sc(), c < 48)
    if (c == '-') f = 1;
  do x = (x << 3) + (x << 1) + (c ^ 48);
  while (c = sc(), c > 47);
  if (f) x = -x;
}
template <class T>
void pt(T x) {
  if (x < 0)
    putchar('-'), x = -x;
  else if (!x)
    putchar('0');
  static int Stk[30], tp = 0;
  for (; x; x /= 10) Stk[tp++] = x % 10;
  while (tp) putchar(Stk[--tp] ^ 48);
}
template <class T>
void ptk(const T &x) {
  pt(x);
  putchar(' ');
}
template <class T>
void ptn(const T &x) {
  pt(x);
  putchar('\n');
}
template <class T>
bool chkmi(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
template <class T>
bool chkmx(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
T gcd(const T &x, const T &y) {
  return y ? gcd(y, x % y) : x;
}
}  // namespace Eddd
using namespace Eddd;
const int N = 500010;
const int Mod = 1e9 + 7;
long long Fast(long long x, long long b) {
  long long t = 1;
  for (; b; b >>= 1, x = x * x % Mod) {
    if (b & 1) t = t * x % Mod;
  }
  return t;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int a[N];
int ans[N];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = (1), _t = (n); i <= _t; ++i) scanf("%d", &a[i]);
  int g = 0;
  for (int i = (0), _t = (29); i <= _t; ++i) {
    int c = 0;
    for (int j = (1), _t = (n); j <= _t; ++j)
      if ((a[j] >> i) & 1) ++c;
    g = gcd(c, g);
  }
  int m = 0;
  for (int i = (1), _t = (n); i <= _t; ++i)
    if (g % i == 0) ans[++m] = i;
  for (int i = (1), _t = (m); i <= _t; ++i)
    printf("%d%c", ans[i], " \n"[i == m]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
