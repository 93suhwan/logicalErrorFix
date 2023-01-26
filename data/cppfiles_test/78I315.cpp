#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "0" << endl;
    } else if ((r - l) == 1) {
      cout << "1" << endl;
    } else if (r % 2 == 0) {
      if (l > (r / 2)) {
        cout << r - l << endl;
      } else {
        cout << (r / 2) - 1 << endl;
      }
    } else if (r % 2 != 0) {
      if (l >= ((r / 2) + 1)) {
        cout << r - l << endl;
      } else {
        cout << r - (r / 2) - 1 << endl;
      }
    }
  }
  return 0;
}
