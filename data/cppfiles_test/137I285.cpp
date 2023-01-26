#include <bits/stdc++.h>
using namespace std;
string sy;
int com(string s1, string s2) {
  if (s1.size() != s2.size()) return 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) return 0;
  }
  return 1;
}
int pr(int st, int en, string s1) {
  int st1 = 0, en1 = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == '0') {
      break;
    }
    st1++;
  }
  for (int i = s1.size() - 1; i >= 0; i--) {
    if (s1[i] == '0') {
      break;
    }
    en1++;
  }
  while (en1 < en) {
    s1 += '1';
    en1++;
  }
  reverse(s1.begin(), s1.end());
  while (st1 < st) {
    s1 += '1';
    st1++;
  }
  reverse(s1.begin(), s1.end());
  return com(s1, sy);
}
int main() {
  long long x, y;
  cin >> x >> y;
  string s1, s2, s3, s4;
  for (int i = 0; y || x; i++) {
    char c1 = (y % 2) + '0';
    char c2 = (x % 2) + '0';
    if (y) sy += c1;
    if (x) s1 += c2;
    y /= 2;
    x /= 2;
  }
  reverse(sy.begin(), sy.end());
  reverse(s1.begin(), s1.end());
  int id = s1.size() - 1;
  while (s1[id] == '0' && id >= 0) {
    id--;
  }
  for (id; id >= 0; id--) {
    s2 += s1[id];
  }
  s3 = s1;
  s3 += '1';
  s4 = s3;
  int st = 0, en = 0;
  string temp;
  reverse(s4.begin(), s4.end());
  for (int i = 0; i < sy.size(); i++) {
    if (sy[i] == '0') {
      break;
    }
    st++;
  }
  for (int i = sy.size() - 1; i >= 0; i--) {
    if (sy[i] == '0') {
      break;
    }
    en++;
  }
  if (st == sy.size()) st = 0;
  string s5 = s2;
  reverse(s5.begin(), s5.end());
  if (pr(st, en, s5) || pr(st, en, s1) || pr(st, en, s2) || pr(st, en, s3) ||
      pr(st, en, s4))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
