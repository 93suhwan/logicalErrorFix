#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int m = abs(a - b) * 2;
    if ((a >= 1 && a <= m) and (b >= 1 && b <= m) and (c >= 1 && c <= m)) {
      int f = a - b;
      if (c + f != 0) {
        cout << abs(c + f) << endl;
      } else
        cout << abs(f) + c << endl;
    } else
      cout << "-1" << endl;
  }
  return 0;
}
