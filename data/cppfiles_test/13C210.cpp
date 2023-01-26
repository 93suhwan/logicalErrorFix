#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int nA = 0;
    int nB = 0;
    int nC = 0;
    cin >> s;
    int i;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'A') {
        nA++;
      } else if (s[i] == 'B') {
        nB++;
      } else {
        nC++;
      }
    }
    if (nA + nC == nB) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
