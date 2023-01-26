#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
const double expt = 1e-8;
long long q_pow(long long a, long long b) {
  long long base = a;
  long long unt = 1;
  while (b) {
    if (b % 2) (unt *= base % mod) %= mod;
    b /= 2;
    (base *= base) %= mod;
  }
  return unt;
}
long long prod(long long x, long long y) {
  (x *= y) %= mod;
  return x;
}
long long add(long long x, long long y) { return (x + y) % mod; }
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
long long divi(long long x, long long y) {
  (x *= q_pow(y, mod - 2)) %= mod;
  return x;
}
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  int unt;
  while (x % y) {
    unt = x % y;
    x = y;
    y = unt;
  }
  return y;
}
long long lcm(long long x, long long y) { return x * y / gcd(x, y); }
int n, m, q;
int sum[maxn];
int ans;
int solve(int qq, int anss) {
  if (qq == 0) return 0;
  qq--;
  int id;
  scanf("%d", &id);
  if (id == 3) {
    printf("%d\n", anss);
    return qq;
  } else {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) swap(x, y);
    if (id == 1) {
      sum[x] += 1;
      if (sum[x] == 1) ans--;
      int aa = solve(qq, anss);
      return aa;
    } else {
      sum[x] -= 1;
      if (sum[x] == 0) ans++;
      int aa = solve(qq, ans);
      return aa;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) sum[i] = 0;
  int u, v;
  ans = n;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &u, &v);
    if (u > v) swap(u, v);
    sum[u] += 1;
  }
  for (int i = 1; i <= n; i++)
    if (sum[i]) ans -= 1;
  scanf("%d", &q);
  while (q) {
    q = solve(q, ans);
  }
  return 0;
}
