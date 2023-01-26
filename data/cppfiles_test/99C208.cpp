#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (size_t j = 0; j < t; j++) {
    int n, one = 0, two = 0, last, first;
    cin >> n;
    string s;
    cin >> s;
    for (int x = 0; x < n; x++) {
      if (s[x] == '1') {
        one++;
      } else {
        if (two == 0) {
          first = x;
        }
        two++;
        last = x;
      }
    }
    if (two == 2 || two == 1) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
    }
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (x == y) {
          cout << "X";
        } else if (s[x] == '1' && s[y] == '1') {
          cout << "=";
        } else if (s[x] == '1' && s[y] == '2') {
          cout << "+";
        } else if (s[x] == '2' && s[y] == '1') {
          cout << "-";
        } else if (s[x] == '2' && s[y] == '2') {
          if (x == first && y == last) {
            cout << "-";
          } else if (x == last && y == first) {
            cout << "+";
          } else if (x < y) {
            cout << "+";
          } else if (x > y) {
            cout << "-";
          }
        }
      }
      cout << endl;
    }
  }
}
