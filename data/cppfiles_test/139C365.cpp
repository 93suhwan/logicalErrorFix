#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
  cin >> T;
  while (T--) {
    cin >> s;
    bool flag = 1;
    if (s.size() % 2 == 1)
      flag = 0;
    else {
      int l = 0, r = s.size() / 2;
      while (r < s.size()) {
        if (s[l] != s[r]) {
          flag = 0;
          break;
        }
        l++;
        r++;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
