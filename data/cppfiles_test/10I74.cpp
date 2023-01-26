#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937_64 rnd;
const long long maxn = 1e4 + 50;
const long long mod = 1e9 + 7;
const long long base = 1e13;
long long get(long long x, long long y, long long x1, long long y1) {
  if (x > x1) swap(x, x1), swap(y, y1);
  return max(0ll, y - x1 + 1);
}
long long mu(long long a, long long n) {
  if (n == 0) return 1;
  long long t = mu(a, n / 2);
  if (n % 2 == 0) return (t * t) % mod;
  return ((t * t) % mod * a) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("t.inp", "r")) {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
  }
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long x, y, x1, y1;
  cin >> x >> y >> x1 >> y1;
  long long ers =
      get(x, x + r - 1, x1, x1 + r - 1) * get(y, y + c - 1, y1, y1 + c - 1);
  cout << mu(k, n * m - r * c) << "\n";
}
