#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using vii = std::vector<int>;
using pii = std::pair<int, int>;
namespace IO {
char buf[(1 << 21)], *p1 = buf, *p2 = buf, buf1[(1 << 21)];
int _ = 0;
inline char gc() {
  return p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 21), stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <class I>
inline I read(I &x) {
  x = 0;
  I f = 1;
  char c = getchar();
  if (c == EOF) {
    return -1;
  }
  while (c < '0' || c > '9') {
    if (c == '-') {
      f = f * (-1);
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x = x * f;
}
template <class I>
inline void write(I x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  int tmp = x > 0 ? x : (-x), cnt = 0;
  if (x < 0) {
    putchar('-');
  }
  while (tmp) {
    buf[cnt++] = (tmp % 10) + '0';
    tmp /= 10;
  }
  while (cnt) {
    putchar(buf[--cnt]);
  }
  return;
}
void _FILE() {}
}  // namespace IO
using namespace IO;
int T, n, m, k;
int ans = 0;
char s[5010][5010];
bool vis[5010][5010];
int check(int x, int y) {
  int res = 0;
  int x1 = y, x2 = y, y1 = x, y2 = x;
  for (int i(1); i <= (100); ++i) {
    if (x1 <= 0 || x2 <= 0 || x1 > m || x2 > m || y1 <= 0 || y2 <= 0) {
      break;
    }
    if (s[y1 - 1][x1 - 1] == '*' && s[y2 - 1][x2 + 1] == '*') {
      x1 = x1 - 1;
      x2 = x2 + 1;
      y1 = y1 - 1;
      y2 = y2 - 1;
      ++res;
    } else {
      return res;
    }
  }
}
void match(int x, int y) {
  if (!vis[x][y]) {
    ++ans;
  }
  vis[x][y] = 1;
  int x1 = y, x2 = y, y1 = x, y2 = x;
  for (int i(1); i <= (100); ++i) {
    if (x1 <= 0 || x2 <= 0 || x1 > m || x2 > m || y1 <= 0 || y2 <= 0) {
      break;
    }
    if (s[y1 - 1][x1 - 1] == '*' && s[y2 - 1][x2 + 1] == '*') {
      if (!vis[y1 - 1][x1 - 1]) {
        ++ans;
      }
      if (!vis[y2 - 1][x2 + 1]) {
        ++ans;
      }
      vis[y1 - 1][x1 - 1] = vis[y2 - 1][x2 + 1] = 1;
      x1 = x1 - 1;
      x2 = x2 + 1;
      y1 = y1 - 1;
      y2 = y2 - 1;
    } else {
      return;
    }
  }
}
int main() {
  _FILE();
  read(T);
  while (T--) {
    memset(s, 0, sizeof s);
    memset(vis, 0, sizeof vis);
    ans = 0;
    read(n), read(m), read(k);
    for (int i(1); i <= (n); ++i) {
      ::cin >> (s[i] + 1);
    }
    for (int i(1); i <= (n); ++i) {
      for (int j(1); j <= (m); ++j) {
        if (s[i][j] == '*') {
          int rest = check(i, j);
          if (rest >= k) {
            match(i, j);
          }
        }
      }
    }
    int answer = 0;
    for (int i(1); i <= (n); ++i) {
      for (int j(1); j <= (m); ++j) {
        if (s[i][j] == '*') {
          ++answer;
        }
      }
    }
    if (ans == answer) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
