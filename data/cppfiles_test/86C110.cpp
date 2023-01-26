#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      ans += 2;
    } else {
      if (i <= n - 2) {
        if (s1[i + 1] != s2[i + 1]) {
          if (s1[i] == '0') {
            ans += 1;
          }
        } else {
          if (s1[i + 1] != s1[i]) {
            ans += 2;
            i++;
          } else {
            if (s1[i] == '0') {
              ans += 1;
            }
          }
        }
      } else {
        if (s1[i] == '0') {
          ans += 1;
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
