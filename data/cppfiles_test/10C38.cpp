#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 7, mod = 1e9 + 7;
int qpow(int x, long long y) {
  int ret = 1;
  for (; y; x = (long long)x * x % mod, y >>= 1)
    if (y & 1) ret = (long long)ret * x % mod;
  return ret;
}
int n, m, k, r, c, ax, bx, ay, by;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(12), cout << fixed;
  cin >> n >> m >> k >> r >> c;
  cin >> ax >> ay >> bx >> by;
  if (ax == bx && ay == by)
    cout << qpow(k, (long long)n * m) << '\n';
  else
    cout << qpow(k, (long long)n * m - (long long)r * c) << '\n';
  return 0;
}
