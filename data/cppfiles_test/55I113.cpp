#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
const double eps = 1e-8;
long long power(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % P)
    if (b & 1) res = res * a % P;
  return res;
}
int main() {
  int __ = 1;
  while (__--) {
    int n;
    cin >> n;
    cout << 6ll * power(4, power(2, n) - 2) % P << "\n";
  }
  return 0;
}
