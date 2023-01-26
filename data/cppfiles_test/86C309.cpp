#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  char a[n + 5], b[n + 5];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] != b[i])
      ans += 2;
    else if (a[i] == '1') {
      if ((a[i + 1] == '0' || b[i + 1] == '0') && (i + 1 <= n)) {
        ans += 2;
        i++;
      }
    } else {
      if ((a[i + 1] == '1' && b[i + 1] == '1') && (i + 1 <= n)) {
        ans++;
        i++;
      }
      ans++;
    }
  }
  cout << ans << '\n';
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
