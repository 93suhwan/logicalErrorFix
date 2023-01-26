#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r % 2 == 0) {
      if (((r + 2) / 2) > l) {
        cout << r % ((r + 2) / 2) << endl;
      } else {
        cout << r % l << endl;
      }
    } else if (r % 2 == 1) {
      if (((r + 1) / 2) > l) {
        cout << r % ((r + 1) / 2) << endl;
      } else {
        cout << r % l << endl;
      }
    }
  }
}
