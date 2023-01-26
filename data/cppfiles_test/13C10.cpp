#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int nA = 0, nB = 0, nC = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A')
        nA++;
      else if (s[i] == 'B')
        nB++;
      else if (s[i] == 'C')
        nC++;
    }
    if (nB == nA + nC)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
