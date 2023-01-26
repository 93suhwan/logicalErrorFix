#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if (r == l)
      ans = 0;
    else {
      int temp = r - l;
      temp = l + (temp / 2);
      ans = r % temp;
    }
    cout << '\t' << ans << '\n';
  }
  return 0;
}
