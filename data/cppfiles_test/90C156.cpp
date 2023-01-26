#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  long long x, y, a, b;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y;
    if (x < y) {
      a = y, b = x;
    } else {
      a = x, b = y;
    }
    long long gcdxy = gcd(a, b);
    long long res = x / gcdxy * y;
    if (res == y) {
      res = res;
    } else if (x >= y) {
      res += y;
    } else {
      long long p = y % x;
      res = y - p / 2;
    }
    cout << res << endl;
  }
  return 0;
}
