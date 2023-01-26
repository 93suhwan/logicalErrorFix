#include <bits/stdc++.h>
using namespace std;
bool F(string s) {
  string s1, s2;
  int abcnt = 0, bacnt = 0;
  s1 = s;
  s2 = s;
  while (s1 != "" and s1.find("ab") != -1) {
    abcnt++;
    s1 = s1.erase(0, s1.find("ab") + 2);
  }
  while (s2 != "" and s2.find("ba") != -1) {
    bacnt++;
    s2 = s2.erase(0, s2.find("ba") + 2);
  }
  if (abcnt != bacnt)
    return true;
  else
    return false;
}
int main() {
  int n, t, abcnt = 0, bacnt = 0;
  string s, s1, s2;
  string res;
  cin >> t;
  while (t > 0) {
    cin >> s;
    if (F(s)) {
      while (F(s)) {
        int i = 1;
        if (s[s.size() - i] == 'a')
          s[s.size() - i] = 'b';
        else
          s[s.size() - i] = 'a';
        i++;
      }
      cout << s << endl;
    } else
      cout << s << endl;
    t--;
    abcnt = 0, bacnt = 0;
  }
}
