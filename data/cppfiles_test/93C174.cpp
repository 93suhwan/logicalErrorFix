#include <bits/stdc++.h>
using namespace std;
template <typename AA>
inline void CMax(AA &u, AA v) {
  if (v > u) u = v;
}
template <typename AA>
inline void CMin(AA &u, AA v) {
  if (v < u) u = v;
}
const double eps = 1E-8;
const int Inf = 0x3f3f3f3f, Mod = 1E9 + 7;
const long long Lnf = 0x3f3f3f3f3f3f3f3f;
template <typename AA>
void read(AA &x) {
  int s = 0;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  c == '-' ? (s = 1, x = 0) : (x = c - '0');
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  if (s) x = -x;
}
template <typename AA, typename... Args>
void read(AA &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename AA>
void print(AA k) {
  int num = 0;
  static char stk[23];
  if (k < 0) {
    putchar('-');
    k = -k;
  }
  while (k) stk[++num] = k % 10 + 48, k /= 10;
  if (!num)
    putchar('0');
  else
    while (num) putchar(stk[num--]);
  putchar('\n');
}
inline int Log2(int x) {
  if (!x)
    return 0;
  else
    return 31 - __builtin_clz(x);
}
void gch(char &ch) {
  do {
    ch = getchar();
  } while (ch == ' ' || ch == '\n');
}
long long Pow(long long d, long long m) {
  long long f = 1;
  while (m) {
    if (m & 1) f = f * d % Mod;
    d = d * d % Mod;
    m >>= 1;
  }
  return f;
}
int T = 1, N, M, S, Q, K;
int s[300030];
void solve() {
  int a, b;
  read(a, b);
  if (s[a - 1] == b)
    print(a);
  else if ((s[a - 1] ^ b) != a)
    print(a + 1);
  else
    print(a + 2);
}
int main() {
  for (int a = (1); a <= (300000); ++a) s[a] = s[a - 1] ^ a;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
