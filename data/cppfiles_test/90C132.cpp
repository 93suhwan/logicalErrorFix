#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mxl = 1e5 + 7;
bool check(long long n, long long pick) {
  for (int i = 2; i <= pick + 1; ++i) {
    if (n % i) return 0;
  }
  return 1;
}
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long x, y;
    cin >> x >> y;
    if (x <= y) {
      cout << y - (y % x) / 2 << "\n";
    } else
      cout << (x + y) << "\n";
  }
  return 0;
}
