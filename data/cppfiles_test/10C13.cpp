#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = (b * b) % mod, e /= 2) {
    if (e & 1) ans = (ans * b) % mod;
  }
  return ans;
}
long long n, m, k, r, c, ax, ay, bx, by;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by) {
    cout << modpow(k, (n * m) % (mod - 1)) << '\n';
  } else {
    cout << modpow(k, (n * m - r * c) % (mod - 1)) << '\n';
  }
}
