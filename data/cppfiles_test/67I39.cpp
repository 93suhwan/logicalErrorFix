#include <bits/stdc++.h>
using namespace std;
void solve() {
  double n, p;
  cin >> n >> p;
  double tmp = n * (n - 1) * (n - 2) / 6 * p;
  for (double i = 1; i <= n; i += 1) {
    double res = 0;
    if (i == 1)
      res = 0.5;
    else if (i == 2)
      res = 2.0;
    else
      res = i * (i - 1) * (i - 2) / 6 + i * (i - 1) / 2 + i / 2;
    if (res >= tmp) {
      cout << (int)i << endl;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
