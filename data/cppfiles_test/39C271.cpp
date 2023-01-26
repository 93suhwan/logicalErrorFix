#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &now) {
  char c = getchar();
  T x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  now = x * f;
}
template <typename T>
inline void print(T x) {
  if (x == 0) return;
  print(x / 10);
  int dig = x % 10;
  printf("%d", dig);
}
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const long long INFll = 1e18;
const double PI = 3.1415926535898;
template <typename T>
T gcd(T a, T b) {
  return (a % b == 0) ? b : gcd(b, a % b);
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
long long kuai(long long b, long long p, long long mod) {
  long long now = b, ans = 1;
  while (p) {
    if (p % 2) ans = ans * now % mod;
    now = now * now % mod;
    p /= 2;
  }
  return ans % mod;
}
long long inv(long long x, long long b = MOD - 2, long long c = MOD) {
  return kuai(x, MOD - 2, MOD);
}
const int dir[8][2] = {{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                       {-1, -1}, {1, 1},  {-1, 1}, {1, -1}};
const int M = 3e2 + 5;
const int N = 1e5 + 10;
int inp[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int W, H;
    scanf("%d%d", &W, &H);
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int w0, h0;
    w0 = x2 - x1;
    h0 = y2 - y1;
    int w, h;
    scanf("%d%d", &w, &h);
    int ans = 1e9;
    if (w0 + w <= W) {
      ans = min({ans, w - x1, x2 - (W - w)});
    }
    if (h0 + h <= H) {
      ans = min({ans, h - y1, y2 - (H - h)});
    }
    if (ans == 1e9) {
      printf("-1\n");
    } else {
      printf("%.10lf\n", max(0.0, 1.0 * ans));
    }
  }
  return 0;
}
