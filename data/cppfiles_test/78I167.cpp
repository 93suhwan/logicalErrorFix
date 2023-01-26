#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, l, r, a, b;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
    }
    b = (r / 2) + 1;
    if (b > l) {
      cout << r % b << endl;
    } else {
      cout << r % l << endl;
    }
  }
  return 0;
}
