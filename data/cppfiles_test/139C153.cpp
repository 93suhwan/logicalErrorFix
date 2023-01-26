#include <bits/stdc++.h>
using namespace std;
int t;
void sovel() {
  string str;
  cin >> str;
  int len = str.length();
  if (len % 2 == 1) {
    cout << "NO" << endl;
    return;
  } else {
    for (int i = 0, j = len / 2; j < len; i++, j++) {
      if (str[i] != str[j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  cin >> t;
  while (t--) {
    sovel();
  }
  return 0;
}
