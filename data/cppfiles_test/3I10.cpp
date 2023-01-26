#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int solver(string s) {
  if (s.length() == 1) {
    if (s == "0") return 1;
    if (s == "_") return 10;
  }
  int _ = 0;
  for (char c : s) {
    _ += (c == '_');
  }
  if (s.back() >= '0' && s.back() <= '9' && s[s.length() - 2] >= '0' &&
      s[s.length() - 2] <= '9') {
    if (s.back() != '0' && s.back() != '5') {
      return 0;
    }
    if (s.back() == '0') {
      if (s[s.length() - 2] != '5' && s[s.length() - 2] != '0') {
        return 0;
      }
    }
    if (s.back() == '5') {
      if (s[s.length() - 2] != '2' && s[s.length() - 2] != '7') {
        return 0;
      }
    }
    return pow(10, _);
  }
}
vector<string> generate(string orig) {
  vector<string> v;
  string dum = orig;
  int x = 0;
  for (char c : orig) x += (c == 'X');
  if (!x) {
    return {orig};
  }
  for (char i = '0'; i <= '9'; i++) {
    for (int j = 0; j < dum.length(); j++) {
      if (dum[j] == 'X') {
        dum[j] = i;
      }
    }
    v.push_back(dum);
    dum = orig;
  }
  return v;
}
int main() {
  string orig;
  cin >> orig;
  if (orig.length() == 1) {
    cout << solver(orig);
    return 0;
  }
  vector<string> v = generate(orig);
  int ans = 0;
  for (string s : v) {
    if (s[0] == '0') {
      cout << 0;
      return 0;
    } else if (s[0] == '_') {
      for (char j = '1'; j <= '9'; j++) {
        s[0] = j;
        ans += solver(s);
      }
    } else {
      ans += solver(s);
    }
  }
  cout << ans << endl;
}
