#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = false;
    int ans = 0;
    while (true) {
      flag = true;
      for (int i = 1; i <= n; i++) {
        if (a[i] != i) flag = false;
      }
      if (flag) break;
      ans++;
      if (ans % 2 == 1) {
        for (int i = 1; i < n - 1; i += 2) {
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      } else {
        for (int i = 2; i <= n - 1; i += 2) {
          if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
      }
    }
    cout << ans << "\n";
  }
}
