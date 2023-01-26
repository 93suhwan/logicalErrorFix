#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  long long ans = 1.0;
  for (long long i = 0; i < r; i++) {
    ans *= n;
    n--;
  }
  while (r > 0) ans /= r, r--;
  return ans;
}
double get_prob(double n, double m) {
  double u = nCr(n - m, 2);
  double v = nCr(n, 3);
  double w = nCr(m, 2);
  double x = nCr(n, 3);
  double y = nCr(m, 3);
  double z = nCr(n, 3);
  return (m * u * 7) / (v * 12) + w * (n - m) / x + y / z;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  double p;
  cin >> n >> p;
  long long i;
  for (i = 0; i <= n; i++) {
    if (p - get_prob(n, i) < 1e-9) break;
  }
  cout << i << endl;
}
