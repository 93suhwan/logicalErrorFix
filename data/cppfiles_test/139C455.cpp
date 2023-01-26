#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    bool flag = true;
    if (n % 2 != 0) {
      flag = false;
    } else {
      if (s.substr(0, (n / 2)) == s.substr(n / 2, n - 1)) {
        flag = true;
      } else {
        flag = false;
      }
    }
    if (flag == true) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
