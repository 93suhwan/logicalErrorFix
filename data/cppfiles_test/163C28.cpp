#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, N = 5e5 + 5;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
inline int expow(int n, int k) {
  int ans = 1;
  for (; k; k >>= 1, n = 1ll * n * n % MOD)
    (k & 1) && (ans = 1ll * ans * n % MOD);
  return ans;
}
struct Vector {
  int k, b;
  Vector(int k = 0, int b = 0) : k(k), b(b){};
  Vector operator+(const Vector &tmp) const {
    return Vector((k + tmp.k) % MOD, (b + tmp.b) % MOD);
  }
  Vector operator*(const int &tmp) const {
    return Vector(1ll * k * tmp % MOD, 1ll * b * tmp % MOD);
  }
} b;
int n, m, s, t, tx, ty, sx, sy, p;
void dfs(int nx, int ny, int dx, int dy) {
  int x = nx + dx, y = ny + dy, fx = dx, fy = dy;
  if (x == 1 || x == n) fx = -fx;
  if (y == 1 || y == m) fy = -fy;
  if (x == s && y == t && fx == sx && fy == sy)
    b = Vector(1, 0);
  else
    dfs(x, y, fx, fy);
  if (nx == tx || ny == ty)
    b = (b + Vector(0, 1)) * p;
  else
    b = b + Vector(0, 1);
}
inline void solve() {
  n = read();
  m = read();
  s = read();
  t = read();
  tx = read();
  ty = read();
  p = (MOD + 1 - 1ll * read() * expow(100, MOD - 2) % MOD) % MOD;
  sx = s + 1 > n ? -1 : 1, sy = t + 1 > m ? -1 : 1;
  dfs(s, t, sx, sy);
  printf("%lld\n", 1ll * b.b * expow(1 - b.k + MOD, MOD - 2) % MOD);
}
int main() {
  for (int T = read(); T; --T) solve();
  return 0;
}
