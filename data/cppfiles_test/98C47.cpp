#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    string key;
    cin >> key;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
      int r = (int)(key.find(s[i]) - key.find(s[i - 1]));
      ans += abs(r);
    }
    cout << ans << endl;
  }
}
