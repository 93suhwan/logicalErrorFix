#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (l < r / 2) {
      cout << (r + 1) / 2 - 1 << endl;
    } else if (l == r / 2) {
      cout << l << endl;
    } else {
      cout << r % l << endl;
    }
  }
  return 0;
}
