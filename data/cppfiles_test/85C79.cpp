#include <bits/stdc++.h>
using namespace std;
const int base = 1331;
void solve() {
  string s;
  cin >> s;
  int flag = 0, i = 0;
  while (i < s.length()) {
    if (flag == 1 && s[i] == '0') {
      flag = 2;
      break;
    }
    if (s[i] == '0')
      while (s[i] == '0' && i < s.length()) flag = 1, i++;
    else
      i++;
  }
  if (flag == 0)
    cout << "0";
  else if (flag == 1)
    cout << "1";
  else
    cout << "2";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
