#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cntA = 0;
    int cntB = 0;
    int cntC = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A')
        cntA++;
      else if (s[i] == 'B')
        cntB++;
      else if (s[i] == 'C')
        cntC++;
    }
    if (s.length() % 2 != 0) {
      cout << "NO";
    } else if (cntA > cntB && cntC > cntB) {
      cout << "NO";
    } else if (cntA == 0 && cntB == cntC) {
      cout << "YES";
    } else if (cntC == 0 && cntB == cntA) {
      cout << "YES";
    } else if (cntA + cntC == cntB) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}
