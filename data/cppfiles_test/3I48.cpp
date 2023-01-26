#include <bits/stdc++.h>
using namespace std;
string s;
long long ans = 0;
void underscore(int x, int place, vector<int> c) {
  if (place == s.length()) {
    if (c[0] && (c[c.size() - 2] * 10 + c.back()) % 25 == 0) ans++;
  } else {
    if (s[place] == 'X') {
      c[place] = x;
      underscore(x, place + 1, c);
    } else if (s[place] == '_') {
      for (int _ = 0; _ < 10; _++) {
        c[place] = _;
        underscore(x, place + 1, c);
      }
    } else {
      c[place] = s[place] - '0';
      underscore(x, place + 1, c);
    }
  }
}
int main() {
  cin >> s;
  if (s.length() == 1) {
    if (s[0] - '0' > 0 && s[0] - '0' < 10)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  } else {
    int numof_ = 0;
    bool XE = false;
    for (int i = 0; i < s.length(); i++)
      if (s[i] == 'X') {
        XE = true;
        break;
      }
    if (s.length() > 3) {
      string s1 = s.substr(s.length() - 2, 2);
      for (int i = 1; i < s.length() - 2; i++) {
        if (s[i] == '_') numof_++;
      }
      s = s[0] + s1;
    }
    vector<int> c(s.length(), int());
    if (!XE)
      underscore(0, 0, c);
    else
      for (int x = 0; x < 10; x++) underscore(x, 0, c);
    cout << ans * pow(10, numof_) << "\n";
  }
}
