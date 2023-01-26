#include <bits/stdc++.h>
using namespace std;
char a[5005][5005];
int b[10000];
int v[10000];
int t, n;
int main() {
  cin >> t;
  while (t--) {
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) a[i][i] = 'X';
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      b[i] = x - '0';
      if (b[i] == 2) cnt++;
    }
    if (cnt == 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (b[i] == 1) {
        for (int j = 1; j <= n; j++) {
          if (i == j) continue;
          a[i][j] = '=';
        }
        continue;
      } else {
        for (int j = 1; j <= n; j++) {
          if (i == j) continue;
          if (j == n + 1 - i) {
            a[i][j] = '+';
            continue;
          }
          a[i][j] = '-';
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int flag = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j][i] == '-') flag = 1;
        if (flag == 1 && b[j] == 1) a[j][i] = '+';
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout << a[i][j];
      cout << endl;
    }
  }
}
