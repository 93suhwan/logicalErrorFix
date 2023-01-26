#include <bits/stdc++.h>
using namespace std;
char ch;
int bo;
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void rd(int &x) {
  x = bo = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline void RD(long long &x) {
  x = bo = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9';
       x = (x << 1) + (x << 3) + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline long long RD() {
  long long x;
  RD(x);
  return x;
}
inline int rd() {
  int x;
  rd(x);
  return x;
}
inline void RD(char *s) {
  for (ch = getchar(); blank(ch); ch = getchar())
    ;
  for (; !blank(ch); ch = getchar()) *s++ = ch;
  *s = 0;
}
inline void RD(char &c) {
  for (ch = getchar(); blank(c); ch = getchar())
    ;
}
template <class T>
inline void OT(T x) {
  static char buf[20];
  char *p1 = buf;
  if (!x) *p1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *p1++ = x % 10 + '0', x /= 10;
  while (p1-- != buf) putchar(*p1);
}
const int maxn = 1e5 + 6;
char s[maxn], t[maxn];
int deal(char *s, char *t) {
  int n = strlen(s);
  int m = strlen(t);
  int p = 0;
  int can = 0;
  for (int i = 0; i < m; i++) {
    while (p < n && s[p] != t[i]) p += 2;
    if (p < n) can++;
    p++;
  }
  if (p < n && (n - p) % 2 != 0) return 0;
  if (can != m) return 0;
  return 1;
}
int main() {
  for (int _ = rd(), Case = 1; Case <= _; Case++) {
    RD(s), RD(t);
    int l = strlen(s);
    int odd = -1, even = -1;
    for (int i = 0; i < l; i++)
      if (s[i] == t[0]) {
        if (i % 2 == 0 && even == -1) even = i;
        if (i % 2 != 0 && odd == -1) odd = i;
        if (even != -1 && odd != -1) break;
      }
    if (even != -1 && deal(s + even, t))
      puts("YES");
    else if (odd != -1 && deal(s + odd, t))
      puts("YES");
    else
      puts("NO");
  }
}
