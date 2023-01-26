#include <bits/stdc++.h>
using namespace std;
bool checkreverse(string qw, string qwe) {
  reverse(qw.begin(), qw.end());
  if (qw == qwe) {
    return true;
  }
  return false;
}
string giveans(string p, string q) {
  string s = p;
  return s;
}
int main() {
  int t;
  cin >> t;
  vector<string> c(t);
  int x = 0;
  while (x < t) {
    string s1, s2, s3;
    cin >> s1 >> s2;
    if (s2.compare("abc") == 0) {
      string a = "";
      string b = "";
      string c = "";
      string d = "";
      for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == 'a') {
          a += "a";
          continue;
        }
        if (s1[i] == 'b') {
          b += "b";
          continue;
        }
        if (s1[i] == 'c') {
          c += "c";
          continue;
        }
        d += s1[i];
      }
      sort(d.begin(), d.end());
      s3 = a + c + b + d;
    } else {
      sort(s1.begin(), s1.end());
      s3 = s1;
    }
    c[x] = s3;
    x++;
  }
  for (int i = 0; i < t; i++) {
    cout << c[i];
    cout << "\n";
  }
}
