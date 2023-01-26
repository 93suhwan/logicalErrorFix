#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int ca = 0, cb = 0, cc = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        ca++;
      } else if (s[i] == 'B') {
        cb++;
      } else {
        cc++;
      }
    }
    if (cb == ca + cc) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
