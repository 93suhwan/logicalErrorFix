#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] != 'E') {
        flag = 0;
      }
    }
    int flag2 = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != 'E') {
        flag2 = 0;
      }
    }
    if (flag == 0 and flag2 == 0) {
      cout << "YES" << endl;
    } else {
      if (s[s.size() - 1] == 'N' and flag == 1) {
        cout << "NO" << endl;
      } else if (s[0] == 'N' and flag2 == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
