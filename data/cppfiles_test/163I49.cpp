#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long ksm(long long x, long long s) {
  long long res = 1, p = x, q = s;
  while (q > 0) {
    if (q & 2) res = (res * p) % mod;
    q = q / 2;
    p = (p * p) % mod;
  }
  return res;
}
long long ny(long long x) { return ksm(x, mod - 2); }
int n, m, r1, r2, c1, c2, Fx, Fy;
long long u, v, P;
bool flag;
void dfs(int x, int y, int fx, int fy) {
  if (x + fx < 1 || x + fx > n) fx = -fx;
  if (y + fy < 1 || y + fy > m) fy = -fy;
  if (x == r1 && y == c1 && fx == Fx && fy == Fy) {
    if (flag)
      flag = false;
    else {
      u = 0;
      v = 1;
      return;
    }
  }
  long long a = 1;
  if (x == r2 || y == c2) a = P;
  dfs(x + fx, y + fy, fx, fy);
  u = ((u + 1) * a % mod) % mod;
  v = (v * a) % mod;
  return;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    flag = true;
    scanf("%d%d%d%d%d%d%lld", &n, &m, &r1, &c1, &r2, &c2, &P);
    P = P * ny(100) % mod;
    P = ((1 - P + mod) % mod + mod) % mod;
    int x = r1, y = c1, fx = 1, fy = 1;
    if (x + fx < 1 || x + fx > n) fx = -fx;
    if (y + fy < 1 || y + fy > m) fy = -fy;
    Fx = fx;
    Fy = fy;
    dfs(x, y, fx, fy);
    long long t = (1 - v + mod) % mod;
    long long ans = ny(t) * u % mod;
    cout << (ans % mod + mod) % mod << "\n";
  }
  return 0;
}
