#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, l, r, i;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l == r)
      cout << 0 << endl;
    else {
      if (r / 2 + 1 > l)
        cout << r % (r / 2 + 1) << endl;
      else
        cout << r % l << endl;
    }
  }
  return 0;
}
