#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
inline long long norm(long long x) {
  while (x >= mod) x -= mod;
  while (x < 0) x += mod;
  return x;
}
long long n, m, rb, cb, rd, cd, p;
int main() {
  ios::sync_with_stdio(0);
  int f;
  cin >> f;
  while (f--) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    long long dr = -1, dc = -1;
    long long u = 0, v = 1;
    long long q = (1 - p * pow(100LL, mod - 2) % mod) % mod;
    for (long long i = 0; i < 4 * (n - 1) * (m - 1); ++i) {
      if (rb == 1 && dr == -1 || rb == n && dr == 1) dr *= -1;
      if (cb == 1 && dc == -1 || cb == m && dc == 1) dc *= -1;
      rb += dr, cb += dc;
      u += 1;
      if (rb == rd || cb == cd) u = norm(u * q % mod), v = norm(v * q % mod);
    }
    cout << norm(u * pow(norm(1LL - v), mod - 2) % mod) << endl;
  }
  cout << endl;
  return 0;
}
