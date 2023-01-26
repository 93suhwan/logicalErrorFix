#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long p;
  cin >> p;
  while (p--) {
    long long l, r;
    cin >> l >> r;
    if (r / 2 + 1 <= l) {
      cout << r % l << endl;
    } else {
      cout << r / 2 - 1 + r % 2 << endl;
    }
  }
}
