#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r, x, sol;
    cin >> l >> r;
    if (r % 2 == 1) {
      x = (r + 1) / 2;
    } else {
      x = (r / 2) + 1;
    }
    sol = r % x;
    if (x < l) {
      cout << (r % l) << endl;
    } else {
      cout << sol << endl;
    }
  }
  return 0;
}
