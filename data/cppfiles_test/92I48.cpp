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
string convert1(string s, int cab, int cba) {
  int i = 0;
  int diff = cab - cba;
  while (i < s.size() - 1 && diff > 0) {
    if (s[i] == 'a' && s[i + 1] == 'b') {
      if (i + 2 < s.size()) {
        if (s[i + 2] != 'a') {
          s[i] = 'b';
          diff--;
        }
      }
    }
    i++;
  }
  return s;
}
string convert2(string s, int cab, int cba) {
  int i = 0;
  int diff = cba - cab;
  while (i < s.size() - 1 && diff > 0) {
    if (s[i] == 'b' && s[i + 1] == 'a') {
      if (i + 2 < s.size()) {
        if (s[i + 2] != 'b') {
          s[i] = 'a';
          diff--;
        }
      }
    }
    i++;
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
      cout << convert1(s, cab, cba) << endl;
    } else {
      cout << convert2(s, cab, cba) << endl;
    }
  }
}
