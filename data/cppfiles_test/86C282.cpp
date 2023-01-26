#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, n, m, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    long long ans = 0;
    for (i = 0; i < n; i++) {
      if (s[0][i] == '0' && s[1][i] == '1')
        ans += 2;
      else if (s[0][i] == '1' && s[1][i] == '0')
        ans += 2;
      else {
        if (s[0][i] == '0' && s[1][i] == '0') {
          l = 1;
          int f = 0;
          for (j = i + 1; j < n;) {
            if (s[0][j] == '0' && s[1][j] == '0')
              j++, l++;
            else if (s[0][j] == '0' && s[1][j] == '1') {
              f = 1;
              break;
            } else if (s[0][j] == '1' && s[1][j] == '0') {
              f = 1;
              break;
            } else
              break;
          }
          if (j == n)
            ans += l, i = j;
          else if (f == 1) {
            ans += l;
            i = j - 1;
          } else
            ans += (l - 1) + 2, i = j;
        } else {
          for (j = i + 1; j < n;) {
            if (s[0][j] == '1' && s[1][j] == '1')
              j++;
            else
              break;
          }
          if (j < n) ans += 2;
          i = j;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
