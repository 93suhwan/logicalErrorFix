#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, a = 1, cnt;
bool check(string s, string t) {
  int x = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'X') {
      if (x == -1)
        x = t[i] - '0';
      else if (x != t[i] - '0')
        return false;
    } else if (s[i] != '_') {
      if (s[i] != t[i]) return false;
    }
  }
  return true;
}
int main() {
  cin >> s;
  n = s.size();
  for (int i = 1; i < n; i++) a *= 10;
  for (int i = a; i < a * 10; i++) {
    if (i % 25) continue;
    t = to_string(i);
    if (check(s, t)) {
      cnt++;
    }
  }
  if (n == 1 && (s[0] == '0' || s[0] == 'X' || s[0] == '_')) cnt++;
  cout << cnt << endl;
  return 0;
}
