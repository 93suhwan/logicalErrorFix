#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
int minn, maxx;
long long ans;
inline int Read() {
  char ch;
  int f = 1;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') f = -1;
  int x = ch ^ 48;
  while ((ch = getchar()) >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48);
  return x * f;
}
inline void Print(const long long x, const char ch = '\n', const bool flg = 1) {
  if (x < 0) {
    putchar('-');
    return Print(-x, ch, flg);
  }
  if (x >= 10) Print(x / 10, ch, 0);
  putchar(x % 10 + 48);
  if (flg) putchar(ch);
  return;
}
inline long long Max(const long long x, const long long y) {
  return x > y ? x : y;
}
inline int Min(const int x, const int y) { return x < y ? x : y; }
int T, h, w;
int main() {
  for (T = Read(); T; T--) {
    w = Read();
    h = Read();
    minn = INF, maxx = -INF;
    ans = -INF;
    int k = Read();
    for (register int i = 1; i <= k; i++) {
      int x = Read();
      minn = Min(minn, x);
      maxx = Max(maxx, x);
    }
    ans = Max(ans, 1ll * (maxx - minn) * h);
    minn = INF, maxx = -INF;
    k = Read();
    for (register int i = 1; i <= k; i++) {
      int x = Read();
      minn = Min(minn, x);
      maxx = Max(maxx, x);
    }
    ans = Max(ans, 1ll * (maxx - minn) * h);
    minn = INF, maxx = -INF;
    k = Read();
    for (register int i = 1; i <= k; i++) {
      int x = Read();
      minn = Min(minn, x);
      maxx = Max(maxx, x);
    }
    ans = Max(ans, 1ll * (maxx - minn) * w);
    minn = INF, maxx = -INF;
    k = Read();
    for (register int i = 1; i <= k; i++) {
      int x = Read();
      minn = Min(minn, x);
      maxx = Max(maxx, x);
    }
    ans = Max(ans, 1ll * (maxx - minn) * w);
    Print(ans);
  }
  return 0;
}
