#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r % 2 == 0) {
      if (l <= r / 2) {
        cout << (r - 1) % r / 2 << endl;
      } else {
        cout << r % l << endl;
      }
    } else {
      if (l <= r / 2) {
        cout << r % (r / 2 + 1) << endl;
      } else {
        cout << r % l << endl;
      }
    }
  }
  return 0;
}
