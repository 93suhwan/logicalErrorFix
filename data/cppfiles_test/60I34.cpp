#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m = a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++)
      if (a[i] != m) {
        ans = min(ans, (a[i]) & (a[i] - 1));
      }
    cout << ans << "\n";
  }
}
