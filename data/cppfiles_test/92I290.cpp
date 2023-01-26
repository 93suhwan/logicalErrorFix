#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, a = 0, b = 0, c, ab = 0, ba = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    if (s[i] == 'b' && s[i + 1] == 'a') ba++;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      a++;
    else
      b++;
  }
  if (ab == ba)
    cout << s << endl;
  else {
    if (ab > ba) {
      if (s[0] == 'a' && s[1] == 'b')
        s[0] = 'b';
      else if (s[n - 2] == 'a' && s[n - 1] == 'b')
        s[n - 1] = 'a';
      else {
        if (a > b) {
          for (int i = 0; i < n; i++) {
            s[i] = 'a';
          }
        } else {
          for (int i = 0; i < n; i++) {
            s[i] = 'b';
          }
        }
      }
    } else {
      if (s[0] == 'b' && s[1] == 'a')
        s[0] = 'a';
      else if (s[n - 2] == 'b' && s[n - 1] == 'a')
        s[n - 1] = 'b';
      else {
        if (a > b) {
          for (int i = 0; i < n; i++) {
            s[i] = 'a';
          }
        } else {
          for (int i = 0; i < n; i++) {
            s[i] = 'b';
          }
        }
      }
    }
    cout << s << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
