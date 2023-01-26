#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  bool x = false;
  string s;
  for (int j = 0; j < t; j++) {
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "no" << endl;
    } else {
      string s1 = s.substr(0, s.length() / 2);
      string s2 = s.substr(s.length() / 2, s.length() / 2);
      if (s1 == s2) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}
