#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 2;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '0') {
        continue;
      }
      while (i + 1 < s.length() && s[i + 1] == s[i]) {
        i++;
      }
      cur++;
    }
    ans = min(ans, cur);
    cout << ans << endl;
  }
  return 0;
}
