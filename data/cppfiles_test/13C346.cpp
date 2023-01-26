#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') cntA++;
      if (s[i] == 'B') cntB++;
      if (s[i] == 'C') cntC++;
    }
    if (cntA + cntC == cntB) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
