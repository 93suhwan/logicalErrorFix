#include <bits/stdc++.h>
using namespace std;
int ured() {
  int re = 0, ch;
  do {
    ch = getchar();
  } while ('9' < ch || ch < '0');
  do {
    re = re * 10 + (ch ^ '0');
  } while ('0' <= (ch = getchar()) && ch <= '9');
  return re;
}
void uwit(int da) {
  int cn = 0, ch[21];
  do {
    ch[++cn] = da - da / 10 * 10;
  } while (da /= 10);
  do {
    putchar('0' ^ ch[cn]);
  } while (--cn);
}
inline void dmax(int& fr, int to) {
  if (fr < to) {
    fr = to;
  }
}
inline void dmin(int& fr, int to) {
  if (fr > to) {
    fr = to;
  }
}
inline int mabs(int da) { return da >= 0 ? da : -da; }
const int _maxn = 200011, _mods = 1000000007;
int t, n, m, pdif;
char s[_maxn];
int main() {
  t = ured();
  while (t--) {
    n = ured();
    m = ured();
    if (m >= 2 * n) {
      uwit((m + 1) / 2 - 1);
    } else {
      uwit(m - n);
    }
    putchar('\n');
  }
  return 0;
}
