#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string str;
  while (t--) {
    cin >> str;
    if (str.length() % 2 != 0) {
      cout << "NO" << endl;
      continue;
    }
    int left = 0;
    int right = str.length() / 2;
    while (right < str.length()) {
      if (str[left++] != str[right++]) {
        cout << "NO" << endl;
        break;
      }
    }
    if (right >= str.length()) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
