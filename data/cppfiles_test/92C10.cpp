#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int ab = 0, ba = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == 'b' && s[i - 1] == 'a') {
        ab++;
      } else if (s[i] == 'a' && s[i - 1] == 'b') {
        ba++;
      }
    }
    if (ab == ba) {
      cout << s << endl;
    } else if (ab > ba) {
      s[0] = 'b';
      cout << s << endl;
    } else {
      s[0] = 'a';
      cout << s << endl;
    }
  }
  return 0;
}
