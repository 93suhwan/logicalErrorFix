#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int mn = 10000001, mx = 0, x = n - 1;
    for (int i = 0; i < n / 2; i++) {
      int p = a[i] + a[x];
      if (p % 2 == 0) {
        mx = max(mx, p / 2);
        mn = min(mn, p / 2);
      } else {
        mx = max((p / 2) + 1, mx);
        mn = min(p / 2, mn);
      }
      x--;
    }
    cout << mx - mn << endl;
  }
  return 0;
}
