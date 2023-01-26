#include <bits/stdc++.h>
using namespace std;
void solve() {
  int ab = 0, ba = 0;
  string s;
  cin >> s;
  int l = s.length();
  for (int i = 0; i < l - 1; i++)
    if (s[i] != s[i + 1])
      if (s[i] == 'a')
        ab++;
      else
        ba++;
  if (ab == ba)
    cout << s << endl;
  else if (ab > ba) {
    if (ab - ba == 1) {
      if (s[0] == 'a' && s[1] == 'b')
        s[0] = 'b';
      else if (s[l - 2] == 'a' && s[l - 1] == 'b')
        s[l - 1] = 'a';
    } else {
      if (s[0] == 'a' && s[1] == 'b') s[0] = 'b';
      if (s[l - 2] == 'a' && s[l - 1] == 'b') s[l - 1] = 'a';
    }
    cout << s << endl;
  } else {
    if (ba - ab == 1) {
      if (s[0] == 'b' && s[1] == 'a')
        s[0] = 'a';
      else if (s[l - 2] == 'b' && s[l - 1] == 'a')
        s[l - 1] = 'b';
    } else {
      if (s[0] == 'b' && s[1] == 'a') s[0] = 'a';
      if (s[l - 2] == 'b' && s[l - 1] == 'a') s[l - 1] = 'b';
    }
    cout << s << endl;
  }
}
int main() {
  int n;
  cin >> n;
  while (n--) solve();
  return 0;
}
