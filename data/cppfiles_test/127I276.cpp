#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s, tt;
  int a, b, c;
  string result;
  while (t--) {
    cin >> s >> tt;
    sort(s.begin(), s.end());
    if (tt == "abc") {
      for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'a') continue;
        if (s[i] == 'b' && s[i + 1] == 'b') {
          break;
        } else {
          swap(s[i], s[i + 1]);
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
