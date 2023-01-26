#include <bits/stdc++.h>
template <class T>
inline T max(const T &x, const T &y) {
  return x > y ? x : y;
}
template <class T>
inline T min(const T &x, const T &y) {
  return x < y ? x : y;
}
template <class T>
inline bool chkmax(T &x, const T &y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool chkmin(T &x, const T &y) {
  return x > y ? x = y, true : false;
}
inline int read() {
  register int x = 0, v = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') v = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * v;
}
const int MAXN = 2e5;
int n;
int a[MAXN | 1];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void solve() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  static int cnt[60];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i)
    for (int j = 30; ~j; --j) cnt[j] += (a[i] >> j) & 1;
  int d = 0;
  for (int i = 0; i <= 30; ++i) d = gcd(d, cnt[i]);
  for (int i = 1; i <= d; ++i) {
    if (d % i == 0) printf("%d ", i);
  }
  if (d == 0) {
    for (int i = 1; i <= n; ++i) printf("%d ", i);
  }
  printf("\n");
}
int main() {
  int cases = read();
  while (cases--) {
    solve();
  }
  return 0;
}
