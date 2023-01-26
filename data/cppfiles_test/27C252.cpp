#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    bool startOdd = (s.length() & 1) ^ (t.length() & 1);
    s += '$';
    t += '$';
    int io = 1, ie = 0;
    int find = 0;
    bool found = false;
    while (find < t.length()) {
      if (startOdd) {
        while (io < s.length()) {
          if (s[io] == t[find]) break;
          io += 2;
        }
        if (io > s.length()) break;
        ie = io + 1;
      } else {
        while (ie < s.length()) {
          if (s[ie] == t[find]) break;
          ie += 2;
        }
        if (ie > s.length()) break;
        io = ie + 1;
      }
      find++;
      startOdd = !startOdd;
      if (find == t.length()) found = true;
    }
    if (found)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
