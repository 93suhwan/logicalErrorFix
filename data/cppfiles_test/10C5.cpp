#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int p = 1e9 + 6;
int n, m, k, r, c, ax, ay, bx, by;
int qpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by)
    cout << qpow(k, 1LL * n * m % p) << endl;
  else
    cout << qpow(k, (1LL * n * m % p - 1LL * r * c % p + p) % p) << endl;
  return 0;
}
