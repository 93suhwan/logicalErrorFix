#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else {
    long long int result = power(x, y / 2) % mod;
    if (y % 2 == 0)
      return (result % mod * result % mod) % mod;
    else
      return (result % mod * result % mod * x % mod) % mod;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w1, h1;
    cin >> w1 >> h1;
    double ans = DBL_MAX;
    vector<double> a(4, 0);
    if (h1 > y1) {
      if (h1 - y1 + y2 > h)
        a[0] = -1;
      else
        a[0] = h1 - y1;
    }
    if (w1 > x1) {
      if (w1 - x1 + x2 > w)
        a[1] = -1;
      else
        a[1] = w1 - x1;
    }
    if (y2 > h - h1) {
      if (y1 - (y2 - h + h1) < 0)
        a[2] = -1;
      else
        a[2] = y2 - h + h1;
    }
    if (x2 > w - w1) {
      if (x1 - (x2 - w + w1) < 0)
        a[3] = -1;
      else
        a[3] = x2 - w + w1;
    }
    int cn = 0;
    for (int i = 0; i < 4; i++) {
      if (a[i] >= 0)
        ans = min(ans, a[i]);
      else
        cn++;
    }
    if (cn == 4)
      cout << "-1" << endl;
    else
      cout << fixed << setprecision(8) << ans << endl;
  }
  return 0;
}
