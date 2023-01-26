#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    bool f = 1;
    cin >> s;
    if (s.size() % 2 == 1)
      cout << "N0" << endl;
    else {
      for (int i = 0; (i * 2) < s.size(); i++) {
        if (s[i] != s[(s.size() / 2) + i]) {
          f = false;
          break;
        }
      }
      if (f)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
