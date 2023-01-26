#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int change = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) change++;
  }
  if (change == 2 && s[0] == '1') {
    cout << "1" << endl;
  } else if (change == 1) {
    cout << "1" << endl;
  } else if (change == 0) {
    if (s[0] == '0')
      cout << "1" << endl;
    else
      cout << "0" << endl;
  } else {
    cout << "2" << endl;
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
