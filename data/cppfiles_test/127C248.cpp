#include <bits/stdc++.h>
using namespace std;
int ab[30];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(ab, 0, sizeof(ab));
    string s;
    string s_;
    string sans;
    map<char, int> yxj;
    yxj['a'] = 3;
    yxj['b'] = 2;
    yxj['c'] = 1;
    cin >> s >> s_;
    for (int i = 0; i < s.length(); i++) {
      ab[s[i] - 'a']++;
    }
    if (s_ == "abc" && ab[0] != 0 && ab[1] != 0 && ab[2] != 0) {
      for (int i = 0; i < ab[0]; i++) cout << 'a';
      for (int i = 1; i <= ab[2]; i++) cout << 'c';
      for (int i = 1; i <= ab[1]; i++) cout << 'b';
      int i = 3;
      while (i <= 25) {
        for (int j = 1; j <= ab[i]; j++) {
          cout << char('a' + i);
        }
        i++;
      }
    } else {
      for (int i = 0; i < ab[0]; i++) cout << 'a';
      for (int i = 1; i <= ab[1]; i++) cout << 'b';
      for (int i = 1; i <= ab[2]; i++) cout << 'c';
      int i = 3;
      while (i <= 25) {
        for (int j = 1; j <= ab[i]; j++) {
          cout << char('a' + i);
        }
        i++;
      }
    }
    cout << endl;
  }
}
