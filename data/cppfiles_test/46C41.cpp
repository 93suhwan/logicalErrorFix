#include <bits/stdc++.h>
using namespace std;
int now, ans, a[200005];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    now = a[n];
    ans = 0;
    for (int i = n - 1; i >= 1; i--)
      if (a[i] > now) {
        now = a[i];
        ans++;
      }
    cout << ans << endl;
  }
}
