#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r == l) {
      cout << 0 << endl;
    } else if (r == (l + 1)) {
      cout << 1 << endl;
    } else {
      if (r % 2 == 0) {
        cout << r / 2 - 1 << endl;
      } else {
        cout << (r - 1) / 2 << endl;
      }
    }
  }
}
