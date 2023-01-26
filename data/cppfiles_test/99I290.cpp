#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int o = 0, t = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        o++;
      } else {
        t++;
      }
    }
    if (t > 0 && o >= t) {
      cout << "NO\n";
    } else {
      char ans[n][n];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            ans[i][j] = 'X';
          } else {
            ans[i][j] = 'A';
          }
        }
      }
      int ans1 = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
          for (int j = 0; j < n; j++) {
            if (i != j) {
              ans[i][j] = '=';
              ans[j][i] = '=';
            }
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
          int flag = 0;
          for (int j = 0; j < n; j++) {
            if (ans[i][j] == 'A') {
              ans[i][j] = '+';
              ans[j][i] = '-';
              flag = 1;
              break;
            }
          }
          if (flag == 0) {
            int flag2 = 0;
            for (int j = 0; j < n; j++) {
              if (ans[i][j] == '+') {
                flag2 = 1;
                break;
              }
            }
            if (flag2 == 0) {
              cout << "NO\n";
              ans1 = 1;
              break;
            }
          }
        }
      }
      if (ans1 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            cout << ans[i][j] << "";
          }
          cout << "\n";
        }
      }
    }
  }
  return 0;
}
