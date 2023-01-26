#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x = 0, y = 0;
    string s;
    cin >> s;
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        cntA++;
      } else if (s[i] == 'B') {
        cntB++;
      } else {
        cntC++;
      }
    }
    if ((cntB - cntA) % 2 == 0) {
      x = 1;
      cntB = cntB - cntA;
    }
    if ((cntC - cntB) % 2 == 0) {
      y = 1;
      cntC = cntC - cntB;
    }
    if (x == 1 && y == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
