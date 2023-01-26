#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, d, m;
    cin >> l >> r;
    if (r % 2)
      d = (r + 1) / 2;
    else
      d = r / 2 + 1;
    if (d >= l && d <= r)
      m = r % d;
    else
      m = r % l;
    cout << m << endl;
  }
  return 0;
}
