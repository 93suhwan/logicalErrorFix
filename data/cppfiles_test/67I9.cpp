#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
double nCr(long long n, long long r) {
  if (n < r) return 0;
  double ans = 1.0;
  for (long long i = 0; i < r; i++) {
    ans *= n;
    n--;
  }
  while (r > 0) ans /= r, r--;
  return ans;
}
double get_prob(double n, double m) {
  return (m * nCr(n - m, 2) * 7) / (nCr(n, 3) * 12) +
         nCr(m, 2) * (n - m) / nCr(n, 3) + nCr(m, 3) / nCr(n, 3);
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
    if (p - get_prob(n, i) < 1e-4) break;
  }
  cout << i << endl;
}
