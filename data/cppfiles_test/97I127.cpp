#include <bits/stdc++.h>
inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
template <class T>
inline bool read(T& x) {
  x = 0;
  char c = gc();
  bool flg = false;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x * 10) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) {
    write(x / 10);
    x %= 10;
  }
  putchar(x | 48);
}
template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}
template <class T>
inline void writesp(T x) {
  write(x);
  putchar(' ');
}
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> mp(n);
  std::vector<std::vector<int>> ans(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    std::cin >> mp[i];
  }
  for (int i = 0; i < n; ++i) {
    int noww = (i & 1) ? 1 : 4;
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '.') {
        ans[i][j] = noww;
      } else if (mp[i - 1][j] == 'X') {
        noww = 5 - noww;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 'X') {
        for (int k = 0; k < 4; ++k) {
          int xx = i + dirx[k];
          int yy = j + diry[k];
          if (mp[xx][yy] == '.') {
            ans[i][j] += ans[xx][yy];
          }
        }
      }
    }
  }
  puts("YES");
  for (auto row : ans) {
    for (auto x : row) {
      writesp(x);
    }
    puts("");
  }
  return 0;
}
