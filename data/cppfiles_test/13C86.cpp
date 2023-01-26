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
      } else if (s[i] == 'C') {
        cntC++;
      }
    }
    if (cntA > cntB) {
      cout << "NO" << endl;
    } else if (cntA <= cntB) {
      cntB = cntB - cntA;
      if (cntB == cntC) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
