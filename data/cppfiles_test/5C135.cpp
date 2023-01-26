#include <bits/stdc++.h>
using namespace std;
string s[200010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s[0];
    cin >> s[n - 1];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[n - 1][i] == '1') {
        if (i > 0) {
          if (s[0][i - 1] == '1') {
            ans++;
            s[0][i - 1] = '2';
            continue;
          }
        }
        if (s[0][i] == '0') {
          ans++;
          s[0][i] = '2';
          continue;
        }
        if (i < n - 1) {
          if (s[0][i + 1] == '1') {
            ans++;
            s[0][i + 1] = '2';
            continue;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
