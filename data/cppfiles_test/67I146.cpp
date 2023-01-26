#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int d = abs(a - b);
    if (d >= 2) {
      if (a > 2 * d || b > 2 * d || c > 2 * d) {
        cout << "-1" << endl;
      } else {
        cout << d << endl;
        if ((c + d) % 2 * d != 0) {
          cout << (c + d) % (2 * d) << endl;
        } else {
          cout << (c + d) << endl;
        }
      }
    } else {
      cout << "-1" << endl;
    }
  }
}
