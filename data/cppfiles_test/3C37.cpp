#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s;
  cin >> s;
  if (((int)(s).size()) == 1)
    return (s[0] == 'X' || s[0] == '_' || s[0] == '0');
  int ans = 0;
  for (int x = 0; x <= 9; ++x) {
    string t = s;
    for (int i = 0; i < ((int)(t).size()); ++i)
      if (t[i] == 'X') t[i] = '0' + x;
    if (t[0] == '0') continue;
    string last = t.substr(((int)(t).size()) - 2, 2);
    int cnt = 0;
    for (string p :
         (((int)(t).size()) > 2 ? vector<string>{"00", "25", "50", "75"}
                                : vector<string>{"25", "50", "75"})) {
      if ((last[0] == p[0] || last[0] == '_') &&
          (last[1] == p[1] || last[1] == '_'))
        cnt++;
    }
    for (int i = 0; i < ((int)(t).size()) - 2; ++i) {
      if (t[i] == '_') cnt *= 10 - (i == 0);
    }
    ans += cnt;
    if (s == t) break;
  }
  return ans;
}
int main() { cout << solve() << "\n"; }
