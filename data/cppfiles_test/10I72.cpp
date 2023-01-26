#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)1e9 + 7;
long long pow_(long long n, long long power) {
  if (power == 0) {
    return 1;
  }
  if (power % 2) {
    return n * pow_(n, power - 1) % mod;
  }
  long long val = pow_(n, power / 2);
  return val * val % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  long long ax2 = ax + r - 1, ay2 = ay + c - 1, bx2 = bx + r - 1,
            by2 = by + c - 1;
  long long sq = (n * m - r * c) % mod;
  sq = (sq % mod + mod) % mod;
  long long res = pow_(k, sq);
  cout << res << '\n';
}
