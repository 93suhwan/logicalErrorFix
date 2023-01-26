#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, x;
  cin >> t;
  while (t--) {
    cin >> x >> n;
    m = n % 4;
    int ans = 0;
    if (m != 0) {
      if (m == 1) {
        ans = -n;
      } else if (m == 2) {
        ans = n - (n - 1);
      } else if (m == 3) {
        ans = n + n - 1 - (n - 2);
      }
      if (x % 2 == 0)
        x += ans;
      else
        x -= ans;
    }
    cout << x << "\n";
  }
}
