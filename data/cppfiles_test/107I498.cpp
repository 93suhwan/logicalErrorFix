#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, i, j;
  cin >> n >> a >> b;
  if ((fabs(a - b) == 1 || a == b) && a + b <= n - 2) {
    int ans[n + 3];
    for (i = 1; i <= n; i++) ans[i] = i;
    int l = 1, r = n, x = 1;
    while (a > 0 || b > 0) {
      if (a > 0) {
        if (x == 1) {
          swap(ans[r], ans[r - 1]);
          r--;
        } else {
          swap(ans[l], ans[l + 1]);
          l++;
        }
        a--;
      }
      if (b > 0) {
        if (x == 0) {
          swap(ans[r], ans[r - 1]);
          r--;
        } else {
          swap(ans[l], ans[l + 1]);
          l++;
        }
        b--;
      }
      if (x == 1) {
        x = 0;
      } else {
        x = 1;
      }
    }
    for (i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
