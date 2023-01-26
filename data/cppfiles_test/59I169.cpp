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
      for (int m = j + 1; m < 5; m++) {
        int first = 0;
        int second = 0;
        int tie = 0;
        for (int n1 = 0; n1 < n; n1++) {
          if (arr[n1][j] == '1' && arr[n1][m] == '1') {
            tie++;
          } else {
            if (arr[n1][j] == '1') {
              second++;
            }
            if (arr[n1][m] == '1') {
              first++;
            }
          }
        }
        if (second + tie >= n / 2 && first + tie >= n / 2) {
          c = 1;
        }
      }
    }
    if (c == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
