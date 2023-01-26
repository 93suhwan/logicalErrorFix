#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int N = 2005;
void change(int x, int y, int v);
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
  if (c[1][1]) change(1, 2, c[1][1]), change(2, 1, c[1][1]);
  if (c[n][n]) change(n, n - 1, c[n][n]), change(n - 1, n, c[n][n]);
  if (c[1][n]) change(1, n - 1, c[1][n]), change(2, n, c[1][n]);
  if (c[n][1]) change(n - 1, 1, c[n][1]), change(n, 2, c[n][1]);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if ((i + j) % 2 == 0) continue;
      if (c[i][j]) change(i + 1, j + 1, -c[i][j]);
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = n; j > 1; --j) {
      if ((i + j) % 2 == 0) continue;
      if (c[i][j]) change(i - 1, j - 1, -c[i][j]);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = n; j > 1; --j) {
      if ((i + j) % 2 == 1) continue;
      if (c[i][j]) change(i + 1, j - 1, -c[i][j]);
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = 1; j < n; ++j) {
      if ((i + j) % 2 == 1) continue;
      if (c[i][j]) change(i - 1, j + 1, -c[i][j]);
    }
  }
  int v = 0;
  for (int i = 3; i < n - 1; ++i) {
    if (c[1][i]) v = c[1][i];
    if (c[n][i]) v = c[n][i];
    if (c[i][1]) v = c[i][1];
    if (c[i][n]) v = c[i][n];
  }
  if (n != 2 && !v) {
    puts("MULTIPLE");
    return 0;
  }
  for (int i = 3; i < n - 1; ++i)
    change(1, i, v), change(n, i, v), change(i, 1, v), change(i, n, v);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (i == j || (i + j) % 2 == 0) continue;
      if (c[i][j]) change(i + 1, j + 1, -c[i][j]);
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = n; j > 1; --j) {
      if (i == j || (i + j) % 2 == 0) continue;
      if (c[i][j]) change(i - 1, j - 1, -c[i][j]);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = n; j > 1; --j) {
      if (i == j || (i + j) % 2 == 1) continue;
      if (c[i][j]) change(i + 1, j - 1, -c[i][j]);
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = 1; j < n; ++j) {
      if (i == j || (i + j) % 2 == 1) continue;
      if (c[i][j]) change(i - 1, j + 1, -c[i][j]);
    }
  }
  c[1][1] = c[n][n] = c[1][2], c[1][n] = c[n][1] = c[1][n - 1];
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
  if (c[x][y] && c[x][y] != v) {
    puts("NONE");
    exit(0);
  }
  c[x][y] = v;
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
