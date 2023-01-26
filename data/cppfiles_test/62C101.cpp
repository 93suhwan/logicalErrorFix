#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 1e3 + 5;
int n, m, q, a[N][N], l[N][N][3];
long long sum;
void change(int x, int y, int c) {
  a[x][y] = c;
  if (c == 1) {
    sum--;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][1] + l[x - i][y - i][2];
      l[x - i][y - i][1] = min(l[x - i][y - i][1], max(2 * i - 1, 0));
      l[x - i][y - i][2] = min(l[x - i][y - i][2], max(2 * i - 1, 0));
      sum += l[x - i][y - i][1] + l[x - i][y - i][2];
    }
    y--;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][1];
      l[x - i][y - i][1] = min(l[x - i][y - i][1], 2 * i);
      sum += l[x - i][y - i][1];
    }
    y++;
    x--;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][2];
      l[x - i][y - i][2] = min(l[x - i][y - i][2], 2 * i);
      sum += l[x - i][y - i][2];
    }
    cout << sum << endl;
  } else {
    sum++;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][1] + l[x - i][y - i][2];
      if (a[x - i][y - i] == 0 && l[x - i][y - i][1] == max(2 * i - 1, 0)) {
        l[x - i][y - i][1] += l[x][y + 1][2] + 1 + (a[x][y + 1] == 1 ? 0 : 1);
      }
      if (a[x - i][y - i] == 0 && l[x - i][y - i][2] == max(2 * i - 1, 0)) {
        l[x - i][y - i][2] += l[x + 1][y][1] + 1 + (a[x + 1][y] == 1 ? 0 : 1);
      }
      sum += l[x - i][y - i][1] + l[x - i][y - i][2];
    }
    sum--;
    sum--;
    l[x][y][2]--;
    l[x][y][1]--;
    y--;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][1];
      if (a[x - i][y - i] == 0 && l[x - i][y - i][1] == 2 * i) {
        l[x - i][y - i][1] +=
            l[x + 1][y + 1][1] + 1 + (a[x + 1][y + 1] == 1 ? 0 : 1);
      }
      sum += l[x - i][y - i][1];
    }
    y++;
    x--;
    for (int i = 0; i <= min(x - 1, y - 1); i++) {
      sum -= l[x - i][y - i][2];
      if (a[x - i][y - i] == 0 && l[x - i][y - i][2] == 2 * i) {
        l[x - i][y - i][2] +=
            l[x + 1][y + 1][2] + 1 + (a[x + 1][y + 1] == 1 ? 0 : 1);
      }
      sum += l[x - i][y - i][2];
    }
    cout << sum << endl;
  }
}
void solve() {
  n = read();
  m = read();
  q = read();
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) a[i][j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = 0;
      l[i][j][1] = 2 * min(n - i, m - j);
      if (m - j > n - i) l[i][j][1]++;
      l[i][j][2] = 2 * min(n - i, m - j);
      if (n - i > m - j) l[i][j][2]++;
      sum += l[i][j][1] + l[i][j][2] + 1;
    }
  }
  int x, y;
  while (q--) {
    x = read();
    y = read();
    if (a[x][y] == 0)
      change(x, y, 1);
    else
      change(x, y, 0);
  }
}
int main() {
  solve();
  return 0;
}
