#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  int t, n;
  string a;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a;
    int l = 0, r = n - 1;
    while (a[l] == a[r] && l <= r) l++, r--;
    if (l > r)
      cout << "0" << endl;
    else {
      int ans1 = 0;
      int l1 = l, r1 = r;
      while (a[l1] == a[l] && l1 <= r1) l1++, ans1++;
      while (a[l1] == a[r1] && l1 <= r1) {
        l1++, r1--;
        if (a[l1] != a[r1]) {
          while (a[l1] == a[l] && l1 < r1) l1++, ans1++;
          while (a[r1] == a[l] && l1 < r1) r1--, ans1++;
        }
      }
      cout << l1 << "  " << r1 << endl;
      if (l1 <= r1) ans1 = -1;
      int ans2 = 0;
      int l2 = l, r2 = r;
      while (a[r2] == a[r] && l2 <= r2) r2--, ans2++;
      while (a[l2] == a[r2] && l2 <= r2) {
        l2++, r2--;
        if (a[l2] != a[r2]) {
          while (a[l2] == a[r] && l2 < r2) l2++, ans2++;
          while (a[r2] == a[r] && l2 < r2) r2--, ans2++;
        }
      }
      if (l2 <= r2) ans2 = -1;
      if (ans1 == -1)
        cout << ans2 << endl;
      else if (ans2 == -1)
        cout << ans1 << endl;
      else
        cout << min(ans1, ans2) << endl;
    }
  }
  return 0;
}
