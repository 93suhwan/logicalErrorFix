#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool p(string s) {
    if (s.size() == 1) {
      return false;
    }
    for (int i = s.size() - 2; i >= 0; i--) {
      if (s[i] == '!' or s[i] == '.' or s[i] == ',') {
        return true;
      }
    }
    return false;
  }
  bool isDigit(string s) {
    for (auto i : s) {
      if (isdigit(i)) {
        return true;
      }
    }
    return false;
  }
  bool check(string s) {
    if (isDigit(s)) {
      return false;
    }
    int hy = count(s.begin(), s.end(), '-');
    if (hy >= 2) {
      return false;
    }
    if (hy == 1) {
      if (s[0] == '-' or s[s.size() - 1] == '-') {
        return false;
      }
    }
    if (p(s)) {
      return false;
    }
    return true;
  }
  int countValidWords(string s) {
    string t;
    stringstream ss(s);
    int cnt = 0;
    while (ss >> t) {
      string k = t;
      if (check(t) and (s[0] != ' ')) {
        cout << "ans->" << k << "<-" << endl;
        cnt++;
      }
    }
    return cnt;
  }
};
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    string t;
    cin >> s >> t;
    if (t != "abc") {
      sort(s.begin(), s.end());
      cout << s;
    } else {
      int a = 0, b = 0, c = 0;
      string res = "";
      for (auto i : s) {
        if (i == 'a') {
          a++;
        } else if (i == 'b') {
          b++;
        } else if (i == 'c') {
          c++;
        } else {
          res += i;
        }
      }
      if (a == 0 or b == 0 or c == 0) {
        sort(s.begin(), s.end());
        cout << s;
      } else {
        sort(res.begin(), res.end());
        string temp = "";
        while (a--) {
          temp += 'a';
        }
        while (c--) {
          temp += 'c';
        }
        while (b--) {
          temp += 'b';
        }
        cout << temp << res;
      }
    }
    cout << endl;
  }
  return 0;
}
