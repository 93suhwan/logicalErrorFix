#include <bits/stdc++.h>
using namespace std;
bool allCharactersSame(string s) {
  int n = s.length();
  for (int i = 1; i < n; i++)
    if (s[i] != s[0]) return false;
  return true;
}
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    int ans = 0;
    cin >> str;
    ans = (str.length() % 2 == 0) ? str.length() / 2 : (str.length() - 1) / 2;
    if (allCharactersSame(str)) ans = 1;
    cout << ans << endl;
  }
  return 0;
}
