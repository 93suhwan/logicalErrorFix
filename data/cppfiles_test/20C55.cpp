#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  T w = 1;
  n = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = getchar();
  }
  n *= w;
}
template <typename T>
inline void write(T x) {
  T l = 0;
  unsigned long long y = 0;
  if (!x) {
    putchar(48);
    return;
  }
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  while (x) {
    y = y * 10 + x % 10;
    x /= 10;
    ++l;
  }
  while (l) {
    putchar(y % 10 + 48);
    y /= 10;
    --l;
  }
}
template <typename T>
inline void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <typename T>
inline void checkmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void checkmin(T &a, T b) {
  a = a < b ? a : b;
}
const int N = 410;
int s0[N][N], s1[N][N], pre[2][N][N];
inline int suan(int opt, int l1, int r1, int l2, int r2) {
  if (opt)
    return s1[l2][r2] - s1[l2][r1 - 1] - s1[l1 - 1][r2] + s1[l1 - 1][r1 - 1];
  else
    return s0[l2][r2] - s0[l2][r1 - 1] - s0[l1 - 1][r2] + s0[l1 - 1][r1 - 1];
}
inline void solve() {
  int n, m, ans = 20;
  read(n);
  read(m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char ch;
      cin >> ch;
      s0[i][j] = s0[i - 1][j] + s0[i][j - 1] - s0[i - 1][j - 1];
      s1[i][j] = s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1];
      if (ch == '1')
        ++s1[i][j];
      else
        ++s0[i][j];
    }
  }
  for (int i = 0; i <= 1; ++i)
    for (int j = 0; j <= m; ++j)
      for (int k = 0; k <= m; ++k) pre[i][j][k] = 0;
  for (int i = 1; i <= n - 4; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = j + 3; k <= m; ++k) {
        if (i > 1)
          pre[i & 1][j][k] = -suan(0, i, j + 1, i, k - 1) +
                             suan(1, i, j + 1, i, k - 1) +
                             suan(0, i - 1, j + 1, i - 1, k - 1) +
                             suan(0, i, j, i, j) + suan(0, i, k, i, k);
        if (i > 1)
          pre[i & 1][j][k] = min(0, pre[(i & 1) ^ 1][j][k] + pre[i & 1][j][k]);
        i += 4;
        int now = suan(0, i, j + 1, i, k - 1) + suan(0, i - 3, j, i - 1, j) +
                  suan(0, i - 3, k, i - 1, k) +
                  suan(0, i - 4, j + 1, i - 4, k - 1) +
                  suan(1, i - 3, j + 1, i - 1, k - 1);
        i -= 4;
        checkmin(ans, now + pre[i & 1][j][k]);
      }
  writeln(ans);
}
int main() {
  int t;
  read(t);
  while (t--) solve();
  return 0;
}
