#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool isAllChar = true;
  for (auto &x : s)
    if (x == '?') {
      isAllChar = false;
      break;
    }
  if (isAllChar)
    cout << s << "\n";
  else {
    bool isAllOther = true;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        isAllOther = false;
        break;
      }
    }
    if (isAllOther) {
      s[0] = 'B';
      for (int i = 1; i < n; ++i)
        if (s[i - 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      cout << s << "\n";
    } else {
      int l = 0, r = 0;
      while (1) {
        while (r < n && s[r] == '?') {
          r++;
        }
        if (r != n) {
          for (int i = r - 1; i >= l; --i) {
            if (s[i + 1] == 'R')
              s[i] = 'B';
            else
              s[i] = 'R';
          }
          while (r < n && s[r] != '?') {
            r++;
          }
          l = r;
        } else {
          for (int i = l; i < n; ++i) {
            if (s[i - 1] == 'R')
              s[i] = 'B';
            else
              s[i] = 'R';
          }
          break;
        }
      }
      cout << s << "\n";
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
