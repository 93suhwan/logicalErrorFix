#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1E9 + 7, INF = 2E18 + 5;
const double PI = 2 * acos(0.0);
const long double EPS = 1.0E-14;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long ans = 0, ans2 = 0, len;
    string s1, s2;
    cin >> len >> s1 >> s2;
    for (int i = 0; i < len; i++) {
      if ((s1[i] == '0' and s2[i] == '1') or (s1[i] == '1' and s2[i] == '0')) {
        ans += 2;
      } else if (s1[i] == '0' and s2[i] == '0') {
        if (i + 1 < len) {
          if (s1[i + 1] == '1' and s2[i + 1] == '1') {
            ans += 2;
            i++;
          } else {
            ans++;
          }
        } else {
          ans++;
        }
      } else if (s1[i] == '1' and s2[i] == '1') {
        if (i + 1 < len) {
          if (s1[i + 1] == '0' and s2[i + 1] == '0') {
            ans += 2;
            i++;
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
