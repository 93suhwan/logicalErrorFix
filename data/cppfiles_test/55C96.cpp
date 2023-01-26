#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
const double eps = 1e-8;
long long power(long long a, long long b, long long p) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) res = res * a % p;
  return res;
}
long long get_phi(long long x) {
  long long res = x, a = x;
  for (long long i = 2; i * i <= x; ++i)
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  if (a > 1) res = res / a * (a - 1);
  return res;
}
int main() {
  int __ = 1;
  while (__--) {
    int n;
    cin >> n;
    long long p = get_phi(P);
    long long up = (power(2, n, p) - 2 + p) % p;
    cout << 6ll * power(4, up, P) % P << "\n";
  }
  return 0;
}
