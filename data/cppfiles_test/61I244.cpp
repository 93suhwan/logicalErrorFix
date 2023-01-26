#include <bits/stdc++.h>
using namespace std;
int imperfect(string &s) {
  int n = s.size(), cnt = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == s[i + 1]) cnt++;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc, n;
  string s;
  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    string s1 = s;
    string s2 = s;
    for (int i = 0, color = 0; i < s.size(); i++) {
      if (s1[i] == '?') {
        s1[i] = (color % 2 ? 'B' : 'R');
      }
      color++;
    }
    for (int i = 0, color = 0; i < s.size(); i++) {
      if (s2[i] == '?') {
        s2[i] = (color % 2 ? 'R' : 'B');
      }
      color++;
    }
    if (imperfect(s1) < imperfect(s2))
      cout << s1 << "\n";
    else
      cout << s2 << "\n";
  }
  return 0;
}
