#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t, i, n, k, ans;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    for (i = n; i > n - k; i--)
      if (a[i] == a[i - k]) ans++;
    for (i = 1; i <= n - 2 * k; i++) ans += a[i];
    cout << ans << endl;
  }
  return 0;
}
