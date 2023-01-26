#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r == 1) {
      cout << 0 << "\n";
    } else {
      if (r / 2 >= l) {
        if (r % 2 == 0)
          cout << (r - 1) % (r / 2) << "\n";
        else
          cout << r % ((r + 1) / 2) << '\n';
      } else {
        cout << (r) % l << '\n';
      }
    }
  }
  return 0;
}
