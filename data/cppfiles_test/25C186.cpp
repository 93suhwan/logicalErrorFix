#include <bits/stdc++.h>
using namespace std;
void testcase2() {
  string s, t;
  cin >> s;
  cin >> t;
  int n = s.length();
  int m = t.length();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < i + m && j < n; j++) {
      int len = j - i + 1;
      int leftlen = m - len;
      int idx = j - leftlen;
      if (idx < 0) {
        continue;
      }
      string sec = s.substr(idx, leftlen);
      reverse(sec.begin(), sec.end());
      if (s.substr(i, len) + sec == t) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
void testcase() {
  string s, t;
  cin >> s;
  cin >> t;
  int sl = s.length();
  int n = t.length();
  int tl = t.length();
  if (sl >= tl && t == s.substr(sl - tl, tl)) {
    cout << "YES" << endl;
    return;
  }
  int low = 0, high = n - 1, flag;
  while (high != 0) {
    if (t[low] == t[high]) {
      int it = 0;
      int jt = high;
      flag = 1;
      while (it < jt) {
        if (t[it] != t[jt]) {
          flag = 0;
          break;
        }
        if (t[it] == t[jt]) {
          it++;
          jt--;
        }
      }
      if (flag) {
        break;
      }
    }
    high--;
  }
  string pal = t.substr(0, (high + 1) / 2 + 1);
  cout << "pal" << pal << endl;
  string lt = t.substr(high + 1, tl - (high + 1));
  cout << "lt" << lt << endl;
  reverse(lt.begin(), lt.end());
  int m = pal.length();
  for (int i = 0; i <= sl - m; i++) {
    string temp = s.substr(i, m);
    if (temp == pal && i >= lt.length()) {
      string curr = s.substr(i - lt.length(), lt.length());
      if (curr == lt) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    testcase2();
    t--;
  }
  return 0;
}
