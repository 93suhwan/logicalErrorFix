#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1003][1003];
void out() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << char(a[i][j]);
    cout << endl;
  }
}
void nxt() {
  for (int i = n; i >= 2; i -= 2) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] || a[i - 1][j]) continue;
      for (int c = 'a'; c <= 'z'; c++) {
        if (c == a[i - 1][j] || c == a[i + 1][j] || c == a[i][j - 1] ||
            c == a[i][j + 1])
          continue;
        if (c == a[i][j] || c == a[i - 2][j] || c == a[i - 1][j - 1] ||
            c == a[i - 1][j + 1])
          continue;
        a[i][j] = a[i - 1][j] = c;
        break;
      }
    }
  }
}
void getc(int x1, int y1, int x2, int y2) {
  for (int c = 'a'; c <= 'z'; c++) {
    if (c == a[x1][y1 - 1] || c == a[x1][y1 + 1] || c == a[x1 + 1][y1] ||
        c == a[x1 - 1][y1])
      continue;
    if (c == a[x2][y2 - 1] || c == a[x2][y2 + 1] || c == a[x2 + 1][y2] ||
        c == a[x2 - 1][y2])
      continue;
    a[x1][y1] = a[x2][y2] = c;
    break;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] = 0;
    if (n * (m / 2) < k) {
      puts("NO");
      continue;
    }
    if (!k) {
      if (n & 1) {
        puts("NO");
        continue;
      }
      puts("YES");
      nxt();
      out();
      continue;
    }
    if (n % 2 && k * 2 < m) {
      puts("NO");
      continue;
    }
    if (n % 2) {
      k -= m / 2;
      if (k & 1) {
        puts("NO");
        continue;
      } else {
        puts("YES");
        for (int i = 2; i <= m; i += 2) {
          getc(1, i, 1, i - 1);
        }
        for (int i = 3; i <= n; i += 2) {
          for (int j = 2; j <= m; j += 2) {
            if (!k) break;
            getc(i, j, i, j - 1);
            getc(i - 1, j, i - 1, j - 1);
            k -= 2;
            if (!k) break;
          }
          if (!k) break;
        }
        nxt();
        out();
        continue;
      }
    } else {
      if (k & 1) {
        puts("NO");
        continue;
      } else {
        puts("YES");
        for (int i = 2; i <= n; i += 2) {
          for (int j = 2; j <= m; j += 2) {
            getc(i, j, i, j - 1);
            getc(i - 1, j, i - 1, j - 1);
            k -= 2;
            if (!k) break;
          }
          if (!k) break;
        }
        nxt();
        out();
        continue;
      }
    }
  }
  return 0;
}
