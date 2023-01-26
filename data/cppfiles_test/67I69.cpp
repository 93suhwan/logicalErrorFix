#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
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
    double res = d * i / (n - 1) + i * d * (i - 1) / (n - 2) +
                 (n - 1 - i) * d * i / (n - 2);
    if (res - p > -eps) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
