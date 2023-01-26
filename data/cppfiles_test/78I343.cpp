#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, l, r, x;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
    } else if (r - l == 1) {
      cout << 1 << endl;
    } else if ((r % l) % 2 != 0 && r > l) {
      cout << (r - (r / 2)) + 1 << endl;
    } else {
      cout << (r - (r / 2)) - 1 << endl;
    }
  }
}
