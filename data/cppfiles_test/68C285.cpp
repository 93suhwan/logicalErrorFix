#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int r = 1;
  while ((r * r) < k) {
    r++;
  }
  if ((r * r) == k) {
    cout << r << " "
         << "1" << endl;
  } else {
    r--;
    if ((k - (r * r)) > (r + 1)) {
      cout << (r + 1) << " " << (((2 * (r + 1)) - 1) - (k - (r * r))) + 1
           << endl;
    } else if ((k - (r * r)) < (r + 1)) {
      cout << (k - (r * r)) << " " << (r + 1) << endl;
    } else {
      cout << r + 1 << " " << r + 1 << endl;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
