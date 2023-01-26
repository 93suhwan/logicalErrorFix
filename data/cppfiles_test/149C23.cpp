#include <bits/stdc++.h>
namespace jr_zlw {
inline __int128 read() {
  __int128 res = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') flag ^= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') res = res * 10 + (ch ^ 48), ch = getchar();
  return flag ? -res : res;
}
template <typename T>
inline T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline T max(T x, T y) {
  return y < x ? x : y;
}
template <typename T>
inline void Swap(T &x, T &y) {
  T tmp = x;
  x = y;
  y = tmp;
}
template <typename T>
inline T abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
inline void rd(T &x) {
  x = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') flag ^= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + (ch ^ 48), ch = getchar();
  flag ? x = -x : 0;
}
inline char rdLow() {
  char ch;
  do ch = getchar();
  while (ch < 'a' || ch > 'z');
  return ch;
}
inline char rdHigh() {
  char ch;
  do ch = getchar();
  while (ch < 'A' || ch > 'Z');
  return ch;
}
inline bool rdBool() {
  char ch;
  do ch = getchar();
  while (ch != '0' && ch != '1');
  return ch ^ 48;
}
inline __int128 rdStr(char *s) {
  __int128 p = 0;
  char ch;
  do ch = getchar();
  while (ch == ' ' || ch == '\n' || ch == '\r');
  while (ch != ' ' && ch != '\n' && ch != '\r' && ~ch)
    s[++p] = ch, ch = getchar();
  return p;
}
template <typename T>
inline void print(T p) {
  if (p > 9) print(p / 10);
  putchar(p % 10 + '0');
}
template <typename T>
inline void Print(T p, char ch) {
  print(p);
  putchar(ch);
}
const __int128 N = 2010;
char s[N];
__int128 a[N];
__int128 dp[N], p, L[N], R[N];
inline void mian() {
  __int128 n = read(), k = read(), x = read() - 1;
  scanf("%s", s + 1);
  for (__int128 i = (1); i <= (n); ++i) a[i] = (s[i] == 'a' ? 1 : 0);
  p = 1;
  R[1] = n;
  dp[1] = 0;
  for (__int128 i = (n); i >= (1); --i)
    if (s[i] == '*')
      dp[p]++, L[p] = i;
    else if (dp[p])
      R[++p] = i - 1, dp[p] = 0;
  for (__int128 i = (1); i <= (p); ++i) dp[i] = dp[i] * k + 1;
  while (x) {
    __int128 res = 1;
    for (__int128 i = (1); i <= (p); ++i) {
      if (dp[i] * res > x) {
        if (i == 1) {
          a[L[1]] = x;
          x = 0;
          break;
        }
        a[L[i]] = x / res;
        x %= res;
        break;
      }
      res = res * dp[i];
    }
  }
  for (__int128 i = (1); i <= (n); ++i)
    for (__int128 j = (1); j <= (a[i]); ++j) putchar(s[i] == 'a' ? 'a' : 'b');
  puts("");
}
}  // namespace jr_zlw
signed main() {
  __int128 T = jr_zlw::read();
  while (T--) jr_zlw::mian();
  return 0;
}
