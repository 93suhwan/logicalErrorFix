#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int t = 0;
    if (str.size() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      for (int i = 0; i < (str.size() - 1) / 2; i++) {
        if (str[i] == str[(str.size() / 2) + i]) {
          t = 0;
        } else {
          t++;
          break;
        }
      }
      if (t == 1) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
