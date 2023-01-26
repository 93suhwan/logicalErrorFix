#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<char, int> m;
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
      long long ans = 0;
      for (int i = 0; i < s.size() - 1; i++) {
        ans = ans + abs(m[s[i]] - m[s[i + 1]]);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
