#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    long long ans = 0;
    long long ans1 = 0;
    if (a == c || b == d) {
      cout << 0 << endl;
    } else {
      if (d < b) {
        ans = (m - d) + (m - b);
      } else if (b < d) {
        ans = d - b;
      }
      if (c < a) {
        ans1 = (n - c) + (n - a);
      } else if (a < c) {
        ans1 = c - a;
      }
      cout << min(ans, ans1) << endl;
    }
  }
  return 0;
}
