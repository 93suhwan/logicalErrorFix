#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000007;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    int a = n;
    int c = m + 1;
    int b = 0;
    for (int i = 30; i >= 0; i--) {
      int x = (a >> i) & 1;
      int y = (c >> i) & 1;
      if (y && !x) b = b + (1 << i);
      if ((a ^ b) >= c) break;
    }
    cout << b << endl;
  }
  return 0;
}
