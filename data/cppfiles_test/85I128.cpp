#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == '0') ans++;
    cout << ans << endl;
  }
}
