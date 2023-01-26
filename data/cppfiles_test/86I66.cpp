#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long int ans = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if (s1[i] == '0' and s2[i] == '0') {
        if (s1[i + 1] == '1' and s2[i + 1] == '1') {
          ans += 2;
          i++;
        } else {
          ans += 1;
        }
      } else if (s1[i] == '1' and s2[i] == '1') {
        if (s1[i + 1] == '0' and s2[i + 1] == '0') {
          ans += 2;
          i++;
        }
      } else {
        ans += 2;
      }
    }
    if (n > 1) {
      if (s1[n - 1] == '0' and s2[n - 1] == '0' and s1[n - 2] == '0' and
          s2[n - 1] == '0') {
        ans += 1;
      } else if ((s1[n - 1] == '0' and s2[n - 1] == '1') or
                 (s1[n - 1] == '1' and s2[n - 1] == '0')) {
        ans += 2;
      }
    } else {
      if (s1[0] == '0' and s2[0] == '0') {
        ans += 1;
      } else if ((s1[0] == '0' and s2[0] == '1') or
                 (s1[0] == '1' and s2[0] == '0')) {
        ans += 2;
      }
    }
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
