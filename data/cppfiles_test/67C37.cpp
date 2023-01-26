#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  long long res = 1;
  for (int i = 0; i < k; ++i) res *= (n - i);
  for (int i = 1; i <= k; ++i) res /= i;
  return res;
}
int main() {
  int n;
  double p;
  cin >> n >> p;
  int ans = 0;
  if (p < eps) {
    cout << 0 << endl;
    return 0;
  }
  double d = 1.0 / n;
  for (int i = 1; i < n; ++i) {
    double c2 = (double)C(n - i, 2) * C(i, 1) / C(n, 3) * 1.0 / 2;
    double c3 = (double)C(n - i, 1) * C(i, 2) / C(n, 3);
    double c4 = (double)C(i, 3) / C(n, 3);
    double res = c2 + c3 + c4;
    if (res - p > -eps) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
