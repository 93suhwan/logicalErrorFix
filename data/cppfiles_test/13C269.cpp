#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
  cin >> s;
  int cnta = 0, cntb = 0, cntc = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A')
      cnta++;
    else if (s[i] == 'B')
      cntb++;
    else
      cntc++;
  }
  if (cnta + cntc == cntb) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
