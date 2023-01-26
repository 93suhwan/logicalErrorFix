#include <bits/stdc++.h>
using namespace std;
int nrA = 0, nrB = 0, nrC = 0;
char s[51];
int main() {
  int t;
  cin >> t;
  while (t--) {
    nrA = 0, nrB = 0, nrC = 0;
    cin >> s;
    int length = strlen(s);
    for (int i = 0; i <= length - 1; i++) {
      if (s[i] == 'A') nrA++;
      if (s[i] == 'B') nrB++;
      if (s[i] == 'C') nrC++;
    }
    if (nrA == 0 && nrB != 0 && nrC != 0) {
      if (nrB == nrC)
        cout << "YES";
      else
        cout << "NO";
    }
    if (nrC == 0 && nrA != 0 && nrB != 0) {
      if (nrA == nrB)
        cout << "YES";
      else
        cout << "NO";
    }
    if (nrB == 0) cout << "NO";
    if (nrA == nrB && nrB == nrC) cout << "NO";
    if (nrC != 0 && nrB != 0 && nrC != 0) {
      if (nrA > nrB && nrA > nrC) cout << "NO";
      if (nrB > nrC && nrB > nrA) {
        if (nrB - nrC == nrA)
          cout << "YES";
        else
          cout << "NO";
      }
      if (nrC > nrB) cout << "NO";
    }
    cout << '\n';
  }
}
