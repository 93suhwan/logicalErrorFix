#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, odd = 0, even = 0, ans1 = 0, ans2 = 0, x;
    cin >> n;
    for (int i = 0; i <= n - 1; i++) {
      cin >> x;
      if (x % 2 == 0) {
        ans1 += abs(i - even * 2);
        even++;
      } else {
        ans2 += abs(i - odd * 2);
        odd++;
      }
    }
    if (abs(even - odd) > 1)
      cout << -1 << endl;
    else if (even == odd)
      cout << min(ans1, ans2) << endl;
    else {
      if (even > odd)
        cout << ans1 << endl;
      else
        cout << ans2 << endl;
    }
  }
  return 0;
}
