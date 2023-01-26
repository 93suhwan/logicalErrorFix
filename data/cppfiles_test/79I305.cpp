#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    long long l, r;
    cin >> l >> r;
    if (l == r)
      cout << 0 << endl;
    else {
      if (l > (r / 2))
        cout << r % l << endl;
      else if (l <= r / 2) {
        long long b = 0, a = 0, t = 0;
        b = r / 2;
        a = r % b;
        t = r % (b + 1);
        cout << max(a, t) << endl;
      }
    }
  }
  return 0;
}
