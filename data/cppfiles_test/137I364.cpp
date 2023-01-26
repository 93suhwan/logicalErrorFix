#include <bits/stdc++.h>
using namespace std;
bool check(string s, string x) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') cnt--;
  for (int i = 0; i < x.size(); i++)
    if (x[i] == '0') cnt++;
  if (cnt) return 0;
  if (s.size() < x.size()) return 0;
  for (int i = 0; i <= (int)s.size() - x.size(); i++) {
    cnt = 1;
    for (int j = 0; j < x.size(); j++) {
      if (x[j] != s[i + j]) {
        cnt = 0;
        break;
      }
    }
    if (cnt) return 1;
  }
  return 0;
}
int main() {
  long long x;
  string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "";
  cin >> x;
  while (x) {
    if (x % 2) {
      s1 = '1' + s1;
      s2 = s2 + '1';
    } else {
      s1 = '0' + s1;
      s2 = s2 + '0';
    }
    x /= 2;
  }
  s4 = s1;
  s5 = s2;
  while (s5[0] == '0') {
    s5.erase(0, 1);
    s4.erase(s4.size() - 1, 1);
  }
  cin >> x;
  while (x) {
    if (x % 2) {
      s3 = '1' + s3;
    } else {
      s3 = '0' + s3;
    }
    x /= 2;
  }
  if (check(s3, s1) || check(s3, s2) || check(s3, s4) || check(s3, s5))
    cout << "YES";
  else
    cout << "NO";
}
