#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;
long long mpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2 == 1) {
      res = res * a;
    }
    b = b / 2;
    a = a * a;
  }
  return res;
}
long long pow1(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = res * a % mod;
    b = b / 2;
    a = a * a % mod;
  }
  return res;
}
int main() {
  long long k;
  cin >> k;
  long long b = 1;
  b = mpow(2LL, k - 1) - 1 + mpow(2, k) - 1 - (mpow(2, k - 1));
  long long ans = pow1(4, b);
  ans = ans * 6 % mod;
  cout << ans << endl;
  return 0;
}
