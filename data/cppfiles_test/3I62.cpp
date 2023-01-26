#include <bits/stdc++.h>
using namespace std;
bool check(int num, string &s) {
  string numS;
  while (num) {
    numS += (num % 10) + '0';
    num /= 10;
  }
  reverse(numS.begin(), numS.end());
  if (s.size() != numS.size()) return false;
  string x;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '_')
      continue;
    else if (s[i] == 'X') {
      if (x.empty()) {
        x += numS[i];
      }
      if (x[0] != numS[i]) return false;
    } else {
      if (s[i] != numS[i]) return false;
    }
  }
  return true;
}
int main() {
  int mx = 100000000;
  string s;
  cin >> s;
  if (s == "0") {
    cout << 1 << '\n';
    return 0;
  }
  int ans = 0;
  for (int i = 25; i < mx; i += 25)
    if (check(i, s)) ans++;
  cout << ans << '\n';
  return 0;
}
