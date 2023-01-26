#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s, int i, int j) {
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count2 = 0, last;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      if (s[i] == '2') {
        count2++;
        m[i] = count2;
        last = i;
      }
    }
    if (count2 == 1) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j)
            cout << "X";
          else if (s[i] == '1')
            cout << "=";
          else if (s[i] == '2') {
            if (s[j] == '1')
              cout << "=";
            else {
              if (m[i] == 1 && m[j] == count2) {
                cout << "-";
              } else if (m[i] == count2 && m[j] == 1) {
                cout << "+";
              } else if (m[j] == m[i] + 1)
                cout << "+";
              else if (m[j] == m[i] - 1)
                cout << "-";
              else
                cout << "=";
            }
          }
        }
        cout << endl;
      }
    }
  }
}
