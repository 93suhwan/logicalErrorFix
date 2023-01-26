#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  char a[n + 5], b[n + 5];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i])
      ans += 2;
    else if (a[i] == '1') {
      if ((a[i + 1] == '0' || b[i + 1] == '0') && (i + 1 <= n)) {
        ans += 2;
        i++;
      }
    } else {
      if ((a[i + 1] == '1' || b[i + 1] == '1') && (i + 1 <= n)) {
        ans++;
        i++;
      }
      ans++;
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
