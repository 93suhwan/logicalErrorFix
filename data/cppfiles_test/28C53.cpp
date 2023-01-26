#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    int r;
    (c % 2 != 0) ? r = 3 : r = 0;
    if (b != 0) {
      if (b % 2 != 0) {
        if (r == 3)
          r = 1;
        else
          r = 2;
      } else {
        if (r == 3)
          r = 1;
        else
          r = 0;
      }
    }
    if (a >= r)
      r = (a - r) % 2;
    else
      r -= a;
    cout << r << endl;
  }
  return 0;
}
