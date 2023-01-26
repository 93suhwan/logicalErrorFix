#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 26; i++) {
      char c;
      scanf("%c", &c);
      m[c] = i;
    }
    getchar();
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
