#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  if (k == 1) {
    cout << 1 << endl << s << endl;
    return;
  }
  for (int i = 0; i < k; i++) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' ||
        s[i] == '9') {
      cout << 1 << endl;
      cout << s[i] << endl;
      return;
    }
  }
  cout << 2 << endl;
  for (int i = 0; i < k; i++) {
    if (s[i] == '2' || s[i] == '5' || s[i] == '7')
      for (int j = i + 1; j < k; j++) {
        if (s[j] != '3') {
          cout << s[i] << s[j] << endl;
          return;
        }
      }
    if (s[i] == '3') {
      for (int j = i + 1; j < k; j++) {
        if (s[j] != '7') {
          cout << 3 << s[j] << endl;
          return;
        }
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
