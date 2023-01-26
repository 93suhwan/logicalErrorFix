#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int cntA = 0, cntB = 0, cntC = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'A')
      cntA++;
    else if (s[i] == 'B')
      cntB++;
    else
      cntC++;
  }
  if (cntB == (cntC + cntA))
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
