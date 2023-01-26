#include <bits/stdc++.h>
using namespace std;
void isSquareString() {
  string str;
  cin >> str;
  if (str.length() % 2 != 0) {
    cout << "NO" << endl;
  } else {
    int l = (str.length()) / 2;
    string ans = "YES";
    for (int i = 0; i < l; i++) {
      if (str[i] != str[l + i]) {
        ans = "NO";
        break;
      }
    }
    cout << ans << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    isSquareString();
  }
  return 0;
}
