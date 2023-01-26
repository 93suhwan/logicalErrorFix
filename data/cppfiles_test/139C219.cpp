#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    string str;
    cin >> str;
    int n = str.length();
    if (n % 2 != 0) {
      cout << "NO" << endl;
    } else {
      int i = n / 2 - 1, j = n - 1;
      while (i >= 0 && j >= n / 2) {
        if (str[i] != str[j]) {
          cout << "NO" << endl;
          break;
        }
        i--;
        j--;
      }
      if (i == -1 && j == n / 2 - 1) {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
