#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2)
      cout << -1;
    else {
      int l, r, x;
      x = a + b;
      if (a == b) {
        l = n, r = n - x;
        while (r < l) {
          cout << l << " " << r << " ";
          l--, r++;
        }
        if (r == l) cout << r << " ";
        for (int i = n - x - 1; i >= 1; i--) cout << i << " ";
      } else if (a > b) {
        l = n, r = n - x;
        while (r < l) {
          cout << r << " " << l << " ";
          r++, l--;
        }
        if (r == l) cout << r << " ";
        for (int i = n - x - 1; i >= 1; i--) cout << i << " ";
      } else {
        r = 1, l = x + 1;
        while (r < l) {
          cout << l << " " << r << " ";
          l--, r++;
        }
        if (r == l) cout << r << " ";
        for (int i = x + 2; i <= n; i++) cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
