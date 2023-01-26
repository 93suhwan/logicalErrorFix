#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, temp, mi, ma, i, ans;
    cin >> a >> b;
    temp = a + b;
    if (temp % 2) {
      mi = max(a, b) - (temp / 2 + 1);
      ma = min(a, b) + (temp / 2 + 1);
      ans = ma - mi + 1;
      cout << ans << endl;
      for (i = mi; i <= ma; i++) {
        cout << i << ' ';
      }
    } else {
      mi = max(a, b) - (temp / 2);
      ma = min(a, b) + (temp / 2);
      ans = (ma - mi) / 2 + 1;
      cout << ans << endl;
      for (i = mi; i <= ma; i += 2) cout << i << ' ';
    }
    cout << endl;
  }
}
