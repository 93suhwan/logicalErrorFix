#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, i, j;
  cin >> n >> a >> b;
  if ((fabs(a - b) == 1 || a == b) && a + b <= n - 2) {
    int ans[n + 3];
    for (i = 1; i <= n; i++) ans[i] = i;
    int l = 1, r = n, x = 1;
    if (n % 2 == 0) {
      l = n / 2;
      r = l + 1;
    } else {
      l = n / 2 - 1;
      r = n / 2 + 1;
    }
    x = min(a, b);
    l -= x, r += x;
    swap(ans[l], ans[r]);
    if (a != b) {
      if (n % 2 == 0) {
        if (a > b) {
          swap(ans[n], ans[n - 1]);
        } else {
          swap(ans[1], ans[2]);
        }
      } else {
        x = n / 2;
        if (a > b) {
          swap(ans[x], ans[x + 1]);
        } else {
          swap(ans[x], ans[x - 1]);
        }
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
