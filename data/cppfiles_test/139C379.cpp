#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int ans = 0;
    string s;
    cin >> s;
    if (s.size() % 2 == 0) {
      for (int j = 0; j < s.size() / 2; j++) {
        if (s[j] != s[s.size() / 2 + j]) {
          ans = 1;
          cout << "NO" << endl;
          break;
        }
      }
      if (ans != 1) {
        cout << "YES" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
