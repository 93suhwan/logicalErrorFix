#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4, M = 1e6 + 5, OO = 0x3f3f3fa3f;
const long long mod = 1e9 + 7;
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
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m >= n - 1 && m <= n * (n - 1) / 2) {
      long long dis;
      if (n == 1)
        dis = 0;
      else if (n == 2 || m == n * (n - 1) / 2)
        dis = 1;
      else
        dis = 2;
      if (dis < k - 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
