#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int l = 0; l < t; l++) {
    cin >> n;
    int k;
    k = 0;
    int c;
    c = 0;
    char arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> arr[i][j];
      }
    }
    for (int j = 0; j < 5; j++) {
      k = 0;
      for (int m = 0; m < n; m++) {
        if (arr[m][j] == '0') {
          k = 1;
        }
      }
      if (k == 0) {
        c = 1;
        break;
      }
    }
    if (c == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
