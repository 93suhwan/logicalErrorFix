#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-15, pi = 3.1415926535897932385;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, inf = 0x7fffffff,
          inf_ = 0x80000000;
const long long Inf = 0x7fffffffffffffffLL, Inf_ = 0x8000000000000000LL;
template <typename T>
inline void read(T &x) {
  x = 0;
  bool flag = false;
  char ch = getchar();
  while (ch < '0' || ch > '9') flag = ch == '-' ? true : false, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch & 15), ch = getchar();
  if (flag) x = -x;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
template <typename T>
void cmx(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void cmn(T &x, T y) {
  if (y < x) x = y;
}
inline void ad(int &x, int y) {
  x += y;
  if (x >= 998244353) x -= 998244353;
}
inline void su(int &x, int y) {
  x -= y;
  if (x < 0) x += 998244353;
}
int Pow(int x, int y) {
  int now = 1;
  for (; y; y >>= 1, x = 1LL * x * x % 998244353)
    if (y & 1) now = 1LL * now * x % 998244353;
  return now;
}
int a[500005], n, f[500005], u[500005], w[500005], top, sum;
int main() {
  read(n);
  for (int i = 1; i <= (n); i++) read(a[i]);
  f[0] = 1;
  int op = 1;
  for (int i = (1); i <= (n); i++) {
    int cur = 0;
    while (top > 0 && w[top] >= a[i]) {
      su(sum, 1LL * w[top] * u[top] % 998244353), ad(cur, u[top--]);
    }
    w[++top] = a[i], u[top] = cur;
    if (op)
      ad(u[top], f[i - 1]);
    else
      su(u[top], f[i - 1]);
    ad(sum, 1LL * w[top] * u[top] % 998244353);
    op ^= 1;
    if (op)
      su(f[i], sum);
    else
      ad(f[i], sum);
  }
  printf("%d\n", f[n]);
  return 0;
}
