#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long int ans = 0, one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' || s2[i] == '1') {
        one = 1;
      }
      if (s1[i] == '0' || s2[i] == '0') {
        zero = 1;
      }
      if (s1[i] == s2[i]) {
        if (s1[i] == '0') {
          if (i + 1 < n && s1[i + 1] == s2[i + 1] && s1[i + 1] == '1') {
            ans += 2;
            i++;
          } else {
            ans++;
          }
        } else if (s1[i] == '1') {
          if (i + 1 < n && s1[i + 1] == s2[i + 1] && s1[i + 1] == '0') {
            ans += 2;
            i++;
          }
        }
      } else {
        ans += 2;
      }
    }
    if (one && zero) {
      ans = max(ans, 2LL);
    } else {
      if (one) {
        ans = max(ans, 0LL);
      }
      if (zero) {
        ans = max(ans, 1LL);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
