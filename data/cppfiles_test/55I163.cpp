#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long, long long, long long);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h;
  cin >> h;
  long long x = pow(2, h) - 2;
  x = x % mod;
  long long p = power(4, x, mod) % mod;
  cout << (6 * p) % mod << endl;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
