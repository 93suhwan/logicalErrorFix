#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int inf = 0x3f3f3f3f;
const int N = 11000;
const int M = 2001;
template <typename T>
inline bool scan_d(T& ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF) return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <typename T>
void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T>
void println(T x) {
  print(x);
  putchar('\n');
}
struct TPoint {
  int x, y, id;
  bool operator<(const TPoint& comp) const {
    if (x != comp.x) return x < comp.x;
    if (y != comp.y) return y < comp.y;
    return id < comp.id;
  }
};
int n;
int a[N], dp[2][M];
void fmain() {
  scan_d(n);
  for (int i = (1); i < (n + 1); ++i) scan_d(a[i]);
  int cur = 0, las = 1;
  for (int i = (0); i < (M); ++i) dp[cur][i] = inf;
  dp[cur][0] = 0;
  for (int i = (1); i < (n + 1); ++i) {
    las = cur;
    cur ^= 1;
    for (int j = (0); j < (M); ++j) dp[cur][j] = inf;
    for (int j = (0); j < (M); ++j) {
      dp[cur][max(0, j - a[i])] =
          min(dp[cur][max(0, j - a[i])], dp[las][j] + a[i]);
      if (j + a[i] < M)
        dp[cur][j + a[i]] = min(dp[cur][j + a[i]], max(0, dp[las][j] - a[i]));
    }
  }
  int res = inf;
  for (int j = (0); j < (M); ++j) res = min(res, j + dp[cur][j]);
  println(res);
}
int main() {
  int T;
  scan_d(T);
  for (int t = (0); t < (T); ++t) {
    fmain();
  }
  return 0;
}
