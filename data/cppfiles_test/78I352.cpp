#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j;
  cin >> t;
  for (j = 1; j <= t; ++j) {
    long long int r, l;
    cin >> l >> r;
    if (l < r / 2) {
      if (r % 2 == 1) cout << (r / 2) << '\n';
      if (r % 2 == 0) cout << (r / 2) - 1 << '\n';
    } else {
      cout << r % l << '\n';
    }
  }
  return 0;
}
