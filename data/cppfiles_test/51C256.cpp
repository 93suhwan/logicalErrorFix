#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long modulo(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b /= 2;
  }
  return x;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (-(n - 1)) << " " << n << "\n";
  }
}
