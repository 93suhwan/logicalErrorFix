#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s.length() == 2 && s[0] == 'E' && s[s.length() - 1] == 'N' ||
          (s[0] == 'N' && s[s.length() - 1] == 'E' && s.length() == 2)) {
        cout << "NO" << endl;
        break;
      }
      cout << "YES" << endl;
      break;
    }
  }
}
