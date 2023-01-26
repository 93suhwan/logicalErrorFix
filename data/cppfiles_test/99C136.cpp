#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int main() {
  cin >> t;
  while (t--) {
    char a[60];
    char book[60][60];
    cin >> n;
    int n1 = 0, n2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (1 && a[i] == '1')
        n1++;
      else
        n2++;
    }
    if (1 && n2 == 1 || n2 == 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) {
        bool flag = 1;
        for (int j = i; j <= n; j++) {
          if (1 && i == j)
            book[i][j] = 'X';
          else {
            if (a[i] == '2' && a[j] == '2') {
              if (flag) {
                book[i][j] = '+';
                book[j][i] = '-';
              } else {
                book[i][j] = '-';
                book[j][i] = '+';
              }
              flag = 0;
            } else if (1 && a[i] == '1' || a[j] == '1') {
              book[i][j] = '=';
              book[j][i] = '=';
            }
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          cout << book[i][j];
        }
        cout << endl;
      }
    }
  }
  return 0;
}
