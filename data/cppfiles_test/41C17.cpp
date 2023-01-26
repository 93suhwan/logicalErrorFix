#include <bits/stdc++.h>
template <typename T>
void read(T &);
template <typename T>
void write(const T &);
const int N = 1005;
void work(int l, int r, int c);
int col[N][N];
int ans = 0;
int n, k;
int main() {
  read(n), read(k);
  work(1, n, 1);
  write(ans), putchar('\n');
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      write(col[i][j]), putchar(' ');
    }
  }
  putchar('\n');
  return 0;
}
void work(int l, int r, int c) {
  if (l == r) return;
  ans = std::max(ans, c);
  int cnt = r - l + 1;
  if (cnt <= k) {
    for (int i = l; i <= r; ++i) {
      for (int j = i + 1; j <= r; ++j) {
        col[i][j] = c;
      }
    }
    return;
  }
  int b = (cnt + k - 1) / k;
  for (int i = l; i <= r; i += b) {
    work(i, std::min(i + b - 1, r), c + 1);
    for (int j = i; j < i + b && j <= n; ++j) {
      for (int k = i + b; k <= n; ++k) {
        col[j][k] = c;
      }
    }
  }
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
