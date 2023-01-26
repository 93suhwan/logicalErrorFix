#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  for (i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int d;
    if (a > b) {
      d = a - b;
      if (2 * d < a || 2 * d < c) {
        cout << -1 << endl;
        continue;
      } else {
        if (c > d) {
          cout << c - d << endl;
        } else {
          cout << c + d << endl;
        }
      }
    } else {
      d = b - a;
      if (2 * d < b || 2 * d < c) {
        cout << -1 << endl;
        continue;
      } else {
        if (c > d) {
          cout << c - d << endl;
        } else {
          cout << c + d << endl;
        }
      }
    }
  }
  return 0;
}
