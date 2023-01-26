#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, l;
    cin >> l >> r;
    if (r - l == 0) {
      cout << 0 << endl;
    } else {
      if (r % 2 == 0) {
        if ((r / 2) + 1 >= l) {
          cout << r / 2 - 1 << endl;
        } else {
          cout << r % l << endl;
        }
      } else {
        if ((r / 2) + 1 >= l) {
          cout << r / 2 << endl;
        } else {
          cout << r % l << endl;
        }
      }
    }
  }
  return 0;
}
