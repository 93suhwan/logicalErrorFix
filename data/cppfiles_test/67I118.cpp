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
  for (int i = 1; i <= n; ++i) {
    if ((double)(i - 1) / (n - 2) - p > -eps) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
