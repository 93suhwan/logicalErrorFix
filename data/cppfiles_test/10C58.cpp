#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int add(int x, int y) {
  x += y;
  while (x >= MOD) {
    x -= MOD;
  }
  while (x < 0) {
    x += MOD;
  }
  return x;
}
int mul(int x, int y) { return (x * 1ll * y) % MOD; }
int binpow(int x, long long y) {
  int z = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      z = mul(z, x);
    }
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k, r, c, ax, ay, bx, by, cells;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by)
    cells = n * m;
  else
    cells = n * m - r * c;
  cout << binpow(k, cells) << "\n";
  return 0;
}
