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
    if (length % 2 == 1)
      cout << "NO";
    else {
      if (nrB == length / 2)
        cout << "YES";
      else
        cout << "NO";
    }
    cout << '\n';
  }
}
