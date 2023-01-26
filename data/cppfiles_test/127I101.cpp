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
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') continue;
        if (s[i] == 'b') {
          for (int j = i + 1; j < s.length(); j++)
            if (s[j] != 'b') {
              swap(s[i], s[j]);
              break;
            }
          break;
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
