#include <bits/stdc++.h>
using namespace std;
int isSquareString(string str) {
  int l = (str.length()) / 2;
  for (int i = 0; i < l; i++) {
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
    if (str.length() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      if (isSquareString(str))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
