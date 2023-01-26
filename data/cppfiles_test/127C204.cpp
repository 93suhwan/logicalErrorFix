#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    map<char, int> ma;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
        ma[s[i]]++;
      }
    }
    if (ma['a'] > 0 && ma['b'] > 0 && ma['c'] > 0 && t.compare("abc") == 0) {
      sort(s.begin(), s.end());
      string temp = "";
      bool flag = true;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
          temp.push_back(s[i]);
        } else if (s[i] == 'b' && flag) {
          flag = false;
          while (ma['c'] != 0) {
            temp.push_back('c');
            ma['c']--;
          }
          while (ma['b'] != 0) {
            temp.push_back('b');
            ma['b']--;
          }
        } else if (s[i] != 'b' && s[i] != 'c') {
          temp.push_back(s[i]);
        }
      }
      cout << temp << endl;
      continue;
    }
    sort(s.begin(), s.end());
    cout << s << endl;
  }
  return 0;
}
