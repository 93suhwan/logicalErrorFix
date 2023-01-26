#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    long long ans = -1e18;
    if (n == 1) {
      ans = ar[0];
      cout << ans << "\n";
    } else if (n == 2) {
      ans = max(ans, max(ar[0], abs(ar[0] - ar[1])));
      cout << ans << "\n";
    } else {
      for (int i = 1; i < n; i++) {
        ans = max(ans, abs(ar[i] - ar[i - 1]));
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
