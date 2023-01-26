#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, k;
    cin >> s >> k;
    int i = 0, ans = 0;
    while (i < n) {
      if (s[i] != k[i]) {
        ans += 2;
        i++;
      } else {
        if (s[i + 1] != s[i] and i + 1 <= n - 1) {
          if (s[i] == '0' and i > 0)
            ans += 3;
          else
            ans += 2;
          i += 2;
        } else {
          if (s[i] == '0') {
            ans++;
          }
          i++;
        }
      }
    }
    cout << ans << endl;
  }
}
