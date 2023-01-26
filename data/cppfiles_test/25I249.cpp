#include <bits/stdc++.h>
using namespace std;
bool found(string s, string t, int i, int chip_pos, int direction) {
  if (direction == 1) {
    if (s[chip_pos + direction] == t[i] && chip_pos < s.length() - 1) {
      if (i == t.length() - 1) return "YES";
      chip_pos++;
      if (found(s, t, i + 1, chip_pos, direction)) return true;
    }
    if (s[chip_pos - direction] == t[i] && chip_pos >= 1) {
      if (i == t.length() - 1) return "YES";
      direction = -1;
      chip_pos--;
      if (found(s, t, i + 1, chip_pos, direction)) return true;
    }
    return false;
  } else {
    if (s[chip_pos + direction] == t[i] && chip_pos >= 1) {
      if (i == t.length() - 1) return "YES";
      chip_pos += direction;
      if (found(s, t, i + 1, chip_pos, direction)) return true;
    }
    return false;
  }
}
string solve() {
  string s, t;
  cin >> s >> t;
  char ch = t[0];
  int pos = 0;
  if (t.size() == 1 && s.find(t) != string::npos) return "YES";
  int direction = 1;
  while (s.find(ch, pos) != string::npos) {
    int chip_pos = int(s.find(ch, pos));
    if (found(s, t, 1, chip_pos, direction)) return "YES";
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
