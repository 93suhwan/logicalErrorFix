#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, n;
    cin >> a >> b >> c;
    n = abs(b - a);
    if ((n == 1) || (2 * n < max(a, b))) {
      cout << -1 << "\n";
    } else if (2 * n >= c) {
      if ((c + n) > 2 * n) {
        cout << abs(c - n) << "\n";
      } else {
        cout << (c + n) << "\n";
      }
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}
