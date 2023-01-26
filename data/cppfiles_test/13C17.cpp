#include <bits/stdc++.h>
using namespace std;
bool removestring(string str) {
  int counta = 0;
  int countb = 0;
  int countc = 0;
  int i = 0;
  for (i = 0; i < str.length(); i++) {
    if (str[i] == 'A') {
      counta++;
    } else if (str[i] == 'B') {
      countb++;
    } else if (str[i] == 'C') {
      countc++;
    }
  }
  if ((countc + counta) == countb) {
    return true;
  }
  return false;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    string s;
    cin >> s;
    if (removestring(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
