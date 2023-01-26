#include <bits/stdc++.h>
using namespace std;
int countab(string s) {
  int count = 0;
  int i = 0;
  while (i < s.size() - 1) {
    if (s[i] == 'a') {
      if (s[i + 1] == 'b') {
        count++;
        i = i + 2;
      } else
        i++;
    } else {
      i++;
    }
  }
  return count;
}
int countba(string s) {
  int count = 0;
  int i = 0;
  while (i < s.size()) {
    if (s[i] == 'b') {
      if (s[i + 1] == 'a') {
        count++;
        i = i + 2;
      } else
        i++;
    } else {
      i++;
    }
  }
  return count;
}
string convert1(string s) {
  if (s[0] == 'a' && s[1] == 'b')
    s[0] = 'b';
  else {
    s[s.size() - 1] = 'a';
  }
  return s;
}
string convert2(string s) {
  if (s[0] == 'b' && s[1] == 'a')
    s[0] = 'a';
  else {
    s[s.size() - 1] = 'b';
  }
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cab = countab(s);
    int cba = countba(s);
    if (cab == cba) {
      cout << s << endl;
    } else if (cab > cba) {
      cout << convert1(s) << endl;
    } else {
      cout << convert2(s) << endl;
    }
  }
}
