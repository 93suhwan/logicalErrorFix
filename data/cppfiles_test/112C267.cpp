#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    s = s * 10 + (ch ^ 48);
    ch = getchar();
  }
  return s * f;
}
inline int Abs(int x) { return x < 0 ? -x : x; }
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Max(int x, int y) { return x > y ? x : y; }
int Q;
int main() {
  Q = read();
  while (Q--) {
    int a = read(), b = read(), c = read(), m = read();
    int Maxn = ((a - 1) + (b - 1) + (c - 1));
    int Minn = Max(Max(a - b - c - 1 <= 0 ? 0 : a - b - c - 1,
                       b - a - c - 1 <= 0 ? 0 : b - a - c - 1),
                   c - a - b - 1 <= 0 ? 0 : c - a - b - 1);
    if (m < Minn || Maxn < m) {
      printf("NO\n");
    } else
      printf("YES\n");
  }
  return 0;
}
