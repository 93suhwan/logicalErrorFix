#include <bits/stdc++.h>
using namespace std;
int t, n, a[200010], ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int now = a[n];
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] > now) {
        ans++;
        now = a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
