#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ans += 2;
    } else {
      if (a[i] == '1') {
        if (i < n - 1) {
          if (a[i + 1] == '0' || b[i + 1] == '0') ans += 2, i++;
        }
      } else {
        if (i < n - 1) {
          if (a[i + 1] == '1' && b[i + 1] == '1')
            ans += 2, i++;
          else
            ans++;
        } else
          ans++;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
