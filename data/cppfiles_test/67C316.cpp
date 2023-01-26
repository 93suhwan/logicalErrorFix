#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, n;
    cin >> a >> b >> c;
    n = 2 * abs(a - b);
    if (c > n || b > n || a > n) {
      cout << -1 << endl;
    } else {
      if (c <= (n / 2)) {
        cout << (c + (n / 2)) << endl;
      } else {
        cout << (c - (n / 2)) << endl;
      }
    }
  }
}
