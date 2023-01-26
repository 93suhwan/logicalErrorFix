#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> prefix(n);
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = -1;
    prefix[0] = mp[s[0]];
    for (int i = 1; i < n; i++) {
      if (i % 2)
        prefix[i] = prefix[i - 1] - mp[s[i]];
      else
        prefix[i] = prefix[i - 1] + mp[s[i]];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      int ans = prefix[r];
      if (l) {
        if ((l - 1) % 2 == 0)
          ans = -(ans - prefix[l - 1]);
        else
          ans = ans - prefix[l - 1];
      }
      ans = abs(ans);
      if (ans) {
        if (ans % 2)
          ans = 1;
        else
          ans = 2;
      }
      cout << ans << "\n";
    }
  }
}
