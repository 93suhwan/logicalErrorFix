#include <bits/stdc++.h>
using namespace std;
string s;
bool check(int i) {
  string n = to_string(i);
  if (n.size() != s.size()) return 0;
  char x = 'X';
  for (int i = 0; i < n.size(); i++) {
    if (s[i] == '_') continue;
    if (s[i] == 'X') {
      if (x == 'X') x = n[i];
      if (x != n[i]) return 0;
    } else if (s[i] != n[i])
      return 0;
  }
  return 1;
}
int main() {
  cin >> s;
  int ans = 0;
  for (int i = 0; i < 1e8; i += 25) {
    ans += check(i);
  }
  cout << ans << endl;
  return 0;
}
