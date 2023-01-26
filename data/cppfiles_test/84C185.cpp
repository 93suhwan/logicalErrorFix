#include <bits/stdc++.h>
using namespace std;
long long exp(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) {
      res = ((res % p) * (x % p)) % p;
    }
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long t = (n + 1) / 2;
    if (t == 1) {
      long long x = s / n;
      cout << x << endl;
    } else {
      long long rest = n - t + 1;
      long long x = s / rest;
      cout << x << endl;
    }
  }
  return 0;
}
