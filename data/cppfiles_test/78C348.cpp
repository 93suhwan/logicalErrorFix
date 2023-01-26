#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  while (cin >> t) {
    while (t--) {
      int l, r;
      cin >> l >> r;
      int o = r / 2;
      if (l <= o && o < r) {
        cout << r % (o + 1) << endl;
      } else {
        cout << r % l << endl;
      }
    }
  }
}
