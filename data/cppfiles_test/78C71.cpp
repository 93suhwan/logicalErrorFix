#include <bits/stdc++.h>
using namespace std;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  nos();
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l > r / 2)
      cout << r - l << '\n';
    else {
      if (r % 2 == 0)
        cout << r / 2 - 1 << '\n';
      else
        cout << r / 2 << '\n';
    }
  }
  return 0;
}
