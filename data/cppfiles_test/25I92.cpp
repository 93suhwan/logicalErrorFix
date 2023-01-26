#include <bits/stdc++.h>
using namespace std;
string solve() {
  string s, t;
  cin >> s >> t;
  char ch = t[0];
  int pos = 0;
  if (t.size() == 1 && s.find(t) != string::npos) return "YES";
  int direction = 1;
  while (s.find(ch, pos) != string::npos) {
    int chip_pos = int(s.find(ch, pos));
    for (int i = 1; i < t.length(); i++) {
      if (direction == 1) {
        if (s[chip_pos + direction] == t[i] && chip_pos < s.length() - 1) {
          if (i == t.length() - 1) return "YES";
          chip_pos++;
          continue;
        }
        if (s[chip_pos - direction] == t[i] && chip_pos >= 1) {
          if (i == t.length() - 1) return "YES";
          direction = -1;
          chip_pos--;
          continue;
        }
        break;
      }
      if (direction == -1) {
        if (s[chip_pos + direction] == t[i] && chip_pos >= 1) {
          if (i == t.length() - 1) return "YES";
          chip_pos += direction;
          continue;
        }
        break;
      }
    }
    pos = int(s.find(ch, pos) + 1);
  }
  return "NO";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) cout << solve() << endl;
  return 0;
}
