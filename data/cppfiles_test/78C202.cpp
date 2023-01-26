#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, m;
    cin >> l >> r;
    if (r - l < l) {
      cout << r - l << endl;
    } else {
      m = (r / 2) + 1;
      cout << r % m << endl;
    }
  }
  return 0;
}
