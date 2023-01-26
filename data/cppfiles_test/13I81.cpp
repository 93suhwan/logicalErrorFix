#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    if (str.size() % 2 != 0 || str.size() == 0) {
      cout << "NO" << endl;
    } else {
      map<string, int> mp;
      for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A') mp["A"]++;
        if (str[i] == 'B') mp["B"]++;
        if (str[i] == 'C') mp["C"]++;
      }
      int ca = mp["A"];
      int cb = mp["B"];
      int cc = mp["C"];
      if (cb == 0) {
        cout << "NO" << endl;
      } else if (ca == 0) {
        if (cb == cc)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else if (cc == 0) {
        if (cb == cb)
          cout << "YES" << endl;
        else
          cout << "NO" << endl;
      } else {
        if (cb >= ca) {
          cb = cb - ca;
          if (cb == cc) cout << "YES" << endl;
        } else
          cout << "NO" << endl;
      }
    }
  }
  return 0;
}
