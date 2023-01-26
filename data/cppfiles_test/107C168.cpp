#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, i, j;
  cin >> n >> a >> b;
  if ((fabs(a - b) == 1 || a == b) && a + b <= n - 2) {
    int ans[n + 3];
    for (i = 1; i <= n; i++) ans[i] = i;
    if (a == b) {
      int x = 2;
      while (a) {
        swap(ans[x], ans[x + 1]);
        x += 2;
        a--;
      }
    } else {
      if (a > b) {
        int x = 2;
        while (b) {
          swap(ans[x], ans[x + 1]);
          x += 2;
          b--;
        }
        swap(ans[n], ans[n - 1]);
      } else {
        int x = n - 1;
        while (a) {
          swap(ans[x], ans[x - 1]);
          x -= 2;
          a--;
        }
        swap(ans[1], ans[2]);
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
