#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int e = 0, z = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1')
      e++;
    else
      z++;
  }
  if (z == 0)
    cout << 0 << "\n";
  else if (e == 0)
    cout << 1 << "\n";
  else {
    int ind = s.find('0');
    while (ind < s.size() && s[ind] != '1') ind++;
    bool ok = false;
    for (int i = ind; i < s.size(); i++) {
      if (s[i] == '0') {
        ok = true;
        break;
      }
    }
    if (ok)
      cout << 2 << "\n";
    else
      cout << 1 << "\n";
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
