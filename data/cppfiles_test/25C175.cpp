#include <bits/stdc++.h>
using namespace std;
bool solve(int i, int sn, int stn, string s, string st, int j, char rl) {
  if (j == stn) {
    return true;
  }
  if (i >= 0 && i < sn) {
    if (s[i] == st[j]) {
      if (rl == 'r')
        return solve(i + 1, sn, stn, s, st, j + 1, 'r') ||
               solve(i - 1, sn, stn, s, st, j + 1, 'l');
      else
        return solve(i - 1, sn, stn, s, st, j + 1, 'l');
    } else
      return false;
  } else
    return false;
}
int main() {
  int t;
  cin >> t;
  for (int g = 1; g <= t; ++g) {
    string s, st;
    cin >> s >> st;
    int sn = s.length();
    int stn = st.length();
    int c = 0;
    for (int i = 0; i < sn; ++i) {
      if (s[i] == st[0]) {
        if (solve(i, sn, stn, s, st, 0, 'r') == true) {
          c = 1;
          cout << "YES";
          break;
        }
      }
    }
    if (!c) cout << "NO";
    if (g != t) cout << "\n";
  }
  return 0;
}
