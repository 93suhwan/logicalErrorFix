#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, d;
    cin >> c >> d;
    if (c == d) {
      if (c == 0)
        cout << 0 << endl;
      else if (c > 0)
        cout << 1 << endl;
      else {
        cout << -1 << endl;
      }
    } else if (abs(c - d) % 2 == 0) {
      cout << 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
