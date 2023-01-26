#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) cout << "0\n";
    int i = 0;
    sort(s.begin(), s.end());
    int r = 0, g = 0;
    if (s.size() != 1) {
      while (i < s.size()) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
          while (s[i] == s[i + 1]) {
            i++;
          }
          r++;
          g++;
        } else if (s[i] != s[i + 1]) {
          if (r >= g)
            g++;
          else if (g > r)
            r++;
        } else if (s[i] == s[i + 1]) {
          r++;
          g++;
          i++;
        }
        i++;
      }
      cout << r << "\n";
    }
  }
  return 0;
}
