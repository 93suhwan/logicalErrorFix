#include <bits/stdc++.h>
using namespace std;
mt19937 rng(1234);
const long long mod = 1e9 + 7;
long long n, m, k, r, c;
long long ax, ay, bx, by;
long long modpow(long long u, long long v) {
  long long res = 1, t = u;
  while (v) {
    if (v & 1) res = res * t % mod;
    t = t * t % mod, v >>= 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.precision(15);
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by) {
    cout << modpow(k, n * m);
    return 0;
  }
  long long comp = n * m - r * c;
  cout << modpow(k, comp);
  return 0;
}
