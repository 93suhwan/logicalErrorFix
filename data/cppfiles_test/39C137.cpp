#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long int a, b;
    cin >> a >> b;
    long long int ans = INT_MAX;
    long long int rw = w - x2;
    long long int lw = x1;
    if (lw + rw >= a && h >= b) {
      ans = min(ans, max((long long int)0, a - max(lw, rw)));
    }
    long long int uh = h - y2;
    long long int dh = y1;
    if (uh + dh >= b && a <= w) {
      ans = min(ans, max((long long int)0, b - max(uh, dh)));
    }
    if (ans == INT_MAX) {
      double res = -1.0000;
      cout << fixed << setprecision(10) << res << "\n";
    } else {
      double res = (double)1.0 * ans;
      cout << fixed << setprecision(10) << res << "\n";
    }
  }
}
