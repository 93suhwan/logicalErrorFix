#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, a, b, c, ab = 0, ba = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    if (s[i] == 'b' && s[i + 1] == 'a') ba++;
  }
  if (ab == ba)
    cout << s << endl;
  else {
    if (ab > ba) {
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') {
          s[i] = 'b';
          break;
        }
      }
    } else {
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'b' && s[i + 1] == 'a') {
          s[i] = 'a';
          break;
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
