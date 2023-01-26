#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int len = s.size();
  int ab = 0, ba = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b')
      ab++;
    else if (s[i] == 'b' && s[i + 1] == 'a')
      ba++;
  }
  if (ab > ba) {
    string sa = s;
    int a = 0, b = 0;
    for (int i = 0; i < len; i++) {
      if (sa[i] == 'a') {
        sa[i] = 'b';
        break;
      }
    }
    for (int i = 0; i < len; i++) {
      if (sa[i] == 'a' && sa[i + 1] == 'b')
        a++;
      else if (sa[i] == 'b' && sa[i + 1] == 'a')
        b++;
    }
    if (a == b) {
      cout << sa << endl;
      return;
    }
    sa = s;
    for (int i = len - 1; i >= 0; i--) {
      if (sa[i] == 'a') {
        sa[i] = 'b';
        break;
      }
    }
  } else if (ba > ab) {
    string sa = s;
    int a = 0, b = 0;
    for (int i = 0; i < len; i++) {
      if (sa[i] == 'b') {
        sa[i] = 'a';
        break;
      }
    }
    for (int i = 0; i < len; i++) {
      if (sa[i] == 'a' && sa[i + 1] == 'b')
        a++;
      else if (sa[i] == 'b' && sa[i + 1] == 'a')
        b++;
    }
    if (a == b) {
      cout << sa << endl;
      return;
    }
    sa = s;
    for (int i = len - 1; i >= 0; i--) {
      if (sa[i] == 'b') {
        sa[i] = 'a';
        break;
      }
    }
  } else
    cout << s << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
