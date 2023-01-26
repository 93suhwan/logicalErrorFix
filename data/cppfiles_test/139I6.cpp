#include <bits/stdc++.h>
using namespace std;
int isPerfectSquareString(string str) {
  int l = (str.length()) / 2;
  for (int i = 0; i < l - 1; i++) {
    if (str[i] == str[l + i]) {
      return 1;
    } else {
      return 0;
    }
  }
}
int main() {
  int t;
  cin >> t;
  string str;
  while (t--) {
    cin >> str;
    if (str.length() == 1) {
      cout << "NO" << endl;
    } else {
      if (isPerfectSquareString(str))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
