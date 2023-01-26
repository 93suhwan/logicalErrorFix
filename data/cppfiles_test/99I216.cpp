#include <bits/stdc++.h>
using namespace std;
char a[5005][5005];
int b[10000];
int t, n;
int main() {
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) a[i][i] = 'X';
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      b[i] = x - '0';
      if (b[i] == 2) cnt++;
    }
    if (cnt == 1 || cnt == 2) {
      cout << "NO" << endl;
      continue;
    }
    if (!cnt) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i == j)
            cout << "X";
          else
            cout << "=";
        }
        cout << endl;
      }
      continue;
    }
    int jsq = 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (b[i] == 2 && jsq == 0) {
        jsq = i;
      }
      int flag = 0;
      if (b[i] == 1) continue;
      for (int j = 1; j <= n; j++) {
        if (i == j || a[i][j] != 0) continue;
        if (b[i] == 2 && cnt == 1 && flag == 0) {
          a[i][jsq] = '+', a[jsq][i] = '-', flag = 1;
          continue;
        }
        if (b[i] == 2 && b[j] == 2 && flag == 0) {
          flag = 1;
          a[i][j] = '+', a[j][i] = '-';
          continue;
        }
      }
      if (b[i] == 2) cnt--;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] != 0)
          cout << a[i][j];
        else
          cout << '=';
      }
      cout << endl;
    }
  }
}
