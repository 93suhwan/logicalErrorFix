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
    long long int j = 0;
    if ((s1[0] == '0' and s2[0] == '1') or (s1[0] == '1' and s2[0] == '0')) {
      ans += 2;
      j++;
    } else if (s1[0] == '0' and s2[0] == '0') {
      ans += 1;
    }
    for (long long int i = 1; i < n; i++) {
      if ((s1[i] == '0' and s2[i] == '1') or (s1[i] == '1' and s2[i] == '0')) {
        ans += 2;
        j = i + 1;
        continue;
      }
      if (j == i) {
        if (s1[i] == '0' and s2[i] == '0') {
          ans++;
        }
      } else {
        if (s1[i] == '0' and s2[i] == '0') {
          if (s1[j] == '1' and s2[j] == '1') {
            ans += 2;
            j = i + 1;
          } else {
            ans++;
            j++;
          }
        } else {
          if (s1[j] == '1' and s2[j] == '1') {
            j++;
          } else {
            ans++;
            j = i + 1;
          }
        }
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
