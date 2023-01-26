#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
unsigned long long power(unsigned long long x, unsigned long long y,
                         unsigned long long p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  unsigned long long k;
  cin >> k;
  if (k == 1) {
    cout << 6 << endl;
  } else {
    cout << (unsigned long long)(power(4, pow(2, k) - 2, mod) * 6 % mod);
  }
}
