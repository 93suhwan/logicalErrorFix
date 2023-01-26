#include <bits/stdc++.h>
using namespace std;
long long int t, n, tr, ans, a[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = tr = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] == i) continue;
      if (a[i] - i == i) {
        tr = 1;
        break;
      }
      ans++;
    }
    if (tr)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
}
