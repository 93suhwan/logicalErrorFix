#include <bits/stdc++.h>
using namespace std;
int ans[105][105];
int del_x[] = {-1, 0, 1, 0}, del_y[] = {0, 1, 0, -1};
void clr(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) ans[i][j] = -1;
  }
}
void ShowAns(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = ans[i][j] + 'a';
      cout << c;
    }
    cout << endl;
  }
}
bool check(int x, int y, int n, int m) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
void InsertTwoPoint(int a, int b, int n, int m, int ex_x, int ex_y) {
  int x, y, i, value;
  map<int, bool> mmap;
  for (i = 0; i < 4; i++) {
    x = del_x[i] + a;
    y = del_y[i] + b;
    if (check(x, y, n, m) && ans[x][y] != -1) mmap[ans[x][y]] = true;
  }
  for (i = 0; i < 4; i++) {
    x = del_x[i] + a + ex_x;
    y = del_y[i] + b + ex_y;
    if (check(x, y, n, m) && ans[x][y] != -1) mmap[ans[x][y]] = true;
  }
  for (i = 0;; i++) {
    if (!mmap[i]) {
      value = i;
      break;
    }
  }
  ans[a][b] = ans[a + ex_x][b + ex_y] = value;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int temp_n, temp_m, n, m, k, i, j, domino, iStart, jStart, value = 0;
    cin >> n >> m >> domino;
    iStart = jStart = 0;
    clr(n, m);
    if (n % 2) {
      domino -= (m / 2);
      for (i = 0; i < m; i += 2) {
        ans[0][i + 1] = ans[0][i] = value;
        value = (value + 1) % 26;
      }
      iStart++;
    }
    if (m % 2) {
      for (i = 0; i < n; i += 2) {
        ans[i][0] = ans[i + 1][0] = value;
        value = (value + 1) % 26;
      }
      jStart++;
    }
    temp_n = n / 2 * 2, temp_m = m / 2 * 2;
    if (domino < 0 || (2 * domino) > (temp_n * temp_m) || domino % 2 ||
        (temp_n * temp_m) % 4)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (i = iStart; i < n && domino; i += 2) {
        for (j = jStart; j < m && domino; j += 2) {
          InsertTwoPoint(i, j, n, m, 0, 1);
          InsertTwoPoint(i + 1, j, n, m, 0, 1);
          domino -= 2;
        }
      }
      for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
          if (ans[i][j] == -1) {
            InsertTwoPoint(i, j, n, m, 1, 0);
          }
        }
      }
      ShowAns(n, m);
    }
  }
}
