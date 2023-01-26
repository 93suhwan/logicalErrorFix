#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long l, r;
    cin >> l >> r;
    if (l > r / 2) {
      cout << r - l << endl;
    } else if (r % 2 == 0) {
      cout << r / 2 - 1 << endl;
    } else {
      cout << r / 2 << endl;
    }
  }
  return 0;
}
