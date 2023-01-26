#include <bits/stdc++.h>
using namespace std;
string i2s(long long x) {
  string res;
  while (x) {
    res += x % 10 + '0';
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
int cal(long long x, long long y) {
  string sx = i2s(x);
  string sy = i2s(y);
  int p = 0, q = 0;
  int res = 0;
  while (p < (int)sx.size()) {
    if (q < (int)sy.size() && sx[p] == sy[q]) {
      ++q;
      ++res;
    }
    ++p;
  }
  return sy.size() - res + sx.size() - res;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ans = 1e9;
    for (long long i = 0; i < 63; ++i) {
      long long x = 1LL << i;
      ans = min(ans, cal(n, x));
    }
    cout << ans << endl;
  }
  return 0;
}
