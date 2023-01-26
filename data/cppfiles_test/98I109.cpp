#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1;
    cin >> s1;
    for (int i = 1; i <= 26; i++) {
      m[s1[i]] = i;
    }
    string s;
    cin >> s;
    if (s.size() < 2) {
      cout << 0 << endl;
      continue;
    } else {
      int ans = 0;
      for (int i = 1; i < s.size(); i++) {
        ans = ans + abs(m[s[i]] - m[s[i - 1]]);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
