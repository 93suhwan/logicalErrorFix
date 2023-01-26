#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l == r)
      cout << 0 << endl;
    else if (l <= r / 2)
      cout << r % (r / 2 + 1) << endl;
    else
      cout << r % l << endl;
  }
}
