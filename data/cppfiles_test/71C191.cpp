#include <bits/stdc++.h>
using namespace std;
string solve1(string s) {
  for (char i = '0'; i <= '9'; i++) {
    string ans(s.length(), i);
    if (ans >= s) {
      return ans;
    }
  }
}
string solve2(string s) {
  string res = solve1(s);
  for (char a = '0'; a <= '9'; a++) {
    for (char b = a + 1; b <= '9'; b++) {
      int f = 1;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] < b) {
          string t = s;
          if (t[i] < a)
            t[i] = a;
          else
            t[i] = b;
          for (int j = i + 1; j < s.length(); j++) t[j] = a;
          if (res > t) res = t;
        }
        if (s[i] != a && s[i] != b) {
          f = 0;
          break;
        }
      }
      if (f) {
        return s;
      }
    }
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  if (k == 1) {
    cout << solve1(s) << "\n";
    return;
  } else
    cout << solve2(s);
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
