#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2) {
      cout << "NO" << endl;
    }
    bool flag = true;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n / 2 + i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
