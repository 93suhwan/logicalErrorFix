#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    double n, p, k;
    cin >> n >> p;
    for (k = 1; k <= n; k++) {
      double ans = 0;
      if (n - k >= 2) ans += (k * (n - k) * (n - k - 1)) / 4;
      if (n - k >= 1) ans += (k * (k - 1) * (n - k)) / 2;
      if (k >= 3) ans += (k * (k - 1) * (k - 2)) / 6;
      ans = (ans * 6) / (n * (n - 1) * (n - 2));
      if (abs(ans - p) <= 1e-5) break;
    }
    cout << k << endl;
  }
  return 0;
}
