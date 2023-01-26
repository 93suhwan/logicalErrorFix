#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 20;
char buf[1 << MaxSize], *p1, *p2;
template <class T>
inline void in(T &x) {
  x = 0;
  register bool f = 0;
  register char c =
      ((p1 == p2) ? (p2 = buf + fread(p1 = buf, 1, 1 << MaxSize, stdin),
                     p1 == p2 ? EOF : *p1++)
                  : *p1++);
  while (c < 47 || c > 58)
    f |= (c == '-'),
        c = ((p1 == p2) ? (p2 = buf + fread(p1 = buf, 1, 1 << MaxSize, stdin),
                           p1 == p2 ? EOF : *p1++)
                        : *p1++);
  while (c > 46 && c < 59)
    x = (x << 3) + (x << 1) + (c & 15),
    c = ((p1 == p2) ? (p2 = buf + fread(p1 = buf, 1, 1 << MaxSize, stdin),
                       p1 == p2 ? EOF : *p1++)
                    : *p1++);
  x = f ? (~x + 1) : x;
}
int main() {
  int T;
  in(T);
  while (T--) {
    long long s, n, k;
    in(s), in(n), in(k);
    puts(s == k || s - n < (n / k) * k ? "YES" : "NO");
  }
  return 0;
}
