#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  long long n, x, y;
  cin >> n;
  vector<long long> a(4, 0);
  for (int i = (0); i < (n); i++) {
    cin >> x >> y;
    if (x % 4 == 0) {
      if (y % 4 == 0)
        a[0]++;
      else
        a[1]++;
    } else {
      if (y % 4 == 0)
        a[2]++;
      else
        a[3]++;
    }
  }
  long long ans = n * (n - 1) / 2 * (n - 2) / 3;
  ans -= a[0] * a[1] * a[2];
  ans -= a[0] * a[1] * a[3];
  ans -= a[0] * a[2] * a[3];
  ans -= a[1] * a[2] * a[3];
  cout << ans << endl;
}
