#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c, k;
    cin >> r >> c >> k;
    if (r % 2 == 0 && c % 2 == 0) {
      if (k % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else if (r % 2 == 0 && c % 2 != 0) {
      if (k <= ((r * c / 2) - r / 2) && (k % 2 == 0))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (k < c / 2)
        cout << "NO" << endl;
      else {
        k = k - c / 2;
        if (k % 2 == 0)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      }
    }
  }
}
