#include <bits/stdc++.h>
using namespace std;
int n, mul, a[3][102], t;
string str1, str2;
int main() {
  cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    cin >> str1 >> str2;
    mul = 1;
    for (int i = 0; i <= n - 1; i++) {
      if (str1[i] != '0' && str2[i] != '0') {
        cout << "NO" << endl;
        mul = 0;
        break;
      }
    }
    if (mul) {
      cout << "YES" << endl;
    }
  }
}
