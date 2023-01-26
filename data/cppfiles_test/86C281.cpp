#include <bits/stdc++.h>
using namespace std;
signed main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, k;
    cin >> n;
    cin >> s >> k;
    int ans = 0;
    string prev = "01";
    for (int i = 0; i < n; i++) {
      if ((s[i] == '0' && k[i] == '1') || (s[i] == '1' && k[i] == '0')) {
        prev = "01";
        ans += 2;
      } else if (s[i] == '0' && k[i] == '0') {
        ans++;
        if (prev == "11") {
          ans++;
          prev = "01";
        } else
          prev = "00";
      } else {
        if (prev == "00") {
          ans++;
          prev = "01";
        } else
          prev = "11";
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
