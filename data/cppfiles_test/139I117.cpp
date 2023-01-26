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
    int left = str.length() / 2;
    int right = str.length() - 1;
    while (left >= 0) {
      if (str[left] != str[right]) {
        cout << "NO" << endl;
        break;
      }
      --left;
      --right;
    }
    if (left < 0) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
