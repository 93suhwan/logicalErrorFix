#include <bits/stdc++.h>
using namespace std;
char a[55][55];
char c[55], str[55];
int player[55];
int main() {
  int x;
  cin >> x;
  while (x--) {
    memset(a, '/0', sizeof(a));
    int len, t = 1, aa = 0, b = 0;
    cin >> len;
    cin.ignore();
    gets(c);
    for (int i = 1; i <= len; i++) {
      str[i] = c[i - 1];
    }
    for (int i = 1; i <= len; i++) {
      if (str[i] == '1') {
        aa++;
      } else {
        b++;
        player[t++] = i;
      }
    }
    for (int i = 1; i < t; i++) {
      cout << player[i] << " ";
    }
    int cnt = len;
    cnt--;
    cnt -= aa;
    cnt = (1 + cnt) * cnt / 2;
    if (cnt >= b) {
      cout << "YES" << endl;
      t--;
      for (int i = 1; i < t; i++) {
        a[player[i]][player[i + 1]] = '+';
        a[player[i + 1]][player[i]] = '-';
      }
      a[player[t]][player[1]] = '+';
      a[player[1]][player[t]] = '-';
      for (int i = 1; i <= len; i++) {
        a[i][i] = 'X';
      }
      for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
          if (a[i][j] == '\0') {
            a[i][j] = '=';
          }
        }
      }
      for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}
