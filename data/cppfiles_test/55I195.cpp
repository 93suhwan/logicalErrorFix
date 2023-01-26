#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y / 2;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long k;
  cin >> k;
  if (k == 1) {
    cout << 6 << endl;
  } else {
    cout << power(4, power(2, k, mod) - 2, mod) * 6 % mod;
  }
}
