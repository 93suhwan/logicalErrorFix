#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    int one = 0, ans = 0;
    for (int i = 0; i < s.length(); i++) {
      m[s[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second >= 2)
        ans++;
      else if (it->second == 1)
        one++;
    }
    ans += one / 2;
    cout << ans << endl;
  }
  return 0;
}
