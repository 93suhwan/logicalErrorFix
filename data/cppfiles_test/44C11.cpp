#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int N = 2005;
void change(int x, int y, int v);
void edge();
int c[N][N];
int n;
int main() {
  read(n);
  if (n & 1) {
    puts("NONE");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch = getchar();
      while (ch != '.' && ch != 'S' && ch != 'G') ch = getchar();
      if (ch == 'S') {
        c[i][j] = 1;
      } else if (ch == 'G') {
        c[i][j] = -1;
      }
    }
  }
  int T = 4;
  while (T--) {
    for (int i = 1; i <= n; i += 2) {
      change(1, i, c[1][i + 1]), change(1, i + 1, c[1][i]);
      change(n, i, c[n][i + 1]), change(n, i + 1, c[n][i]);
      change(i, 1, c[i + 1][1]), change(i + 1, 1, c[i][1]);
      change(i, n, c[i + 1][n]), change(i + 1, n, c[i][n]);
    }
    edge();
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        if ((i + j) % 2 == 0) continue;
        change(i + 1, j + 1, -c[i][j]);
      }
    }
    for (int i = n; i > 1; --i) {
      for (int j = n; j > 1; --j) {
        if ((i + j) % 2 == 0) continue;
        change(i - 1, j - 1, -c[i][j]);
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = n; j > 1; --j) {
        if ((i + j) % 2 == 1) continue;
        change(i + 1, j - 1, -c[i][j]);
      }
    }
    for (int i = n; i > 1; --i) {
      for (int j = 1; j < n; ++j) {
        if ((i + j) % 2 == 1) continue;
        change(i - 1, j + 1, -c[i][j]);
      }
    }
    for (int i = 1; i <= n; i += 2) {
      change(1, i, c[1][i + 1]), change(1, i + 1, c[1][i]);
      change(n, i, c[n][i + 1]), change(n, i + 1, c[n][i]);
      change(i, 1, c[i + 1][1]), change(i + 1, 1, c[i][1]);
      change(i, n, c[i + 1][n]), change(i + 1, n, c[i][n]);
    }
  }
  bool flag = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      flag |= !c[i][j];
    }
  }
  if (flag) {
    puts("MULTIPLE");
    return 0;
  }
  puts("UNIQUE");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (c[i][j] == 1)
        putchar('S');
      else
        putchar('G');
    }
    putchar('\n');
  }
  return 0;
}
void change(int x, int y, int v) {
  if (!v) return;
  if (c[x][y] && c[x][y] != v) {
    puts("NONE");
    exit(0);
  }
  c[x][y] = v;
}
void edge() {
  change(1, 1, c[1][2]), change(1, 1, c[2][1]);
  change(n, n, c[n - 1][n]), change(n, n, c[n][n - 1]);
  change(1, n, c[1][n - 1]), change(1, n, c[2][n]);
  change(n, 1, c[n - 1][1]), change(n, 1, c[n][2]);
  change(1, 2, c[1][1]), change(2, 1, c[1][1]);
  change(n, n - 1, c[n][n]), change(n - 1, n, c[n][n]);
  change(1, n - 1, c[1][n]), change(2, n, c[1][n]);
  change(n - 1, 1, c[n][1]), change(n, 2, c[n][1]);
}
template <typename T>
void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!std::isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (std::isdigit(ch)) k = k * 10 + ch - '0', ch = getchar();
  Re = flag * k;
}
template <typename T>
void write(const T &Wr) {
  if (Wr < 0)
    putchar('-'), write(-Wr);
  else if (Wr < 10)
    putchar(Wr + '0');
  else
    write(Wr / 10), putchar((Wr % 10) + '0');
}
