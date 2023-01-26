#include <bits/stdc++.h>
const int N = 2e5 + 10;
const int M = 9699690;
const int mod = 1e9 + 7, Gi = 332748118;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int SIZE = 1 << 21;
char ibuf[SIZE], *iS, *iT;
using std::pair;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
int random(int i) { return rand() % i + 1; }
template <class T>
void ckmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void ckmin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
inline int plus(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qp(int d, int k) {
  int f = 1;
  while (k) {
    if (k & 1) f = (1ll * (f) * (d) % mod);
    d = (1ll * (d) * (d) % mod), k >>= 1;
  }
  return f;
}
int n, a[N], dp[2][N];
long long f[N];
void work() {
  read(n);
  for (int i = (1); i <= (n); i++) read(a[i]);
  for (int i = (1); i <= (n >> 1); i++) std::swap(a[i], a[n + 1 - i]);
  for (int i = (1); i <= (n); i++) f[i] = f[i - 1] + a[i];
  for (int i = (1); i <= (n); i++) dp[1][i] = a[i];
  int k = 2;
  while (233) {
    int cur = k & 1, mx = 0, yuu = 0;
    for (int i = (1); i <= (k); i++) dp[cur][i] = 0;
    for (int i = (k + 1); i <= (n); i++) {
      ckmax(mx, dp[cur ^ 1][i - k]);
      if (f[i] - f[i - k] < 1ll * mx) ckmax(yuu, (int)(f[i] - f[i - k]));
      dp[cur][i] = yuu;
    }
    if (yuu == 0) {
      printf("%d\n", k - 1);
      return;
    }
    ++k;
  }
}
int main() {
  int T = 1;
  read(T);
  while (T--) work();
  return 0;
}
