#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int n, a[N + 9][N + 9];
void into() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    static char s[N + 9];
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j) a[i][j] = s[j] == '.' ? -1 : s[j] == 'S';
  }
}
int ans;
template <typename T>
void Get_ans(int p, int c, T f) {
  int x = p, y = 1;
  for (++x; 2333; ++x, ++y, c ^= 1) {
    f(x, y, c);
    if (x == n) break;
  }
  for (++y; 2333; --x, ++y, c ^= 1) {
    f(x, y, c);
    if (y == n) break;
  }
  for (--x; 2333; --x, --y, c ^= 1) {
    f(x, y, c);
    if (x == 1) break;
  }
  for (--y; 2333; ++x, --y, c ^= 1) {
    f(x, y, c);
    if (y == 1) break;
  }
}
void Get_ans() {
  if (n & 1) return;
  ans = 1;
  for (int i = 1; i <= n; i += 2) {
    int flag = 1;
    auto Check = [&](int x, int y, int c) {
      if (a[x][y] == !c) flag = 0;
    };
    auto Cover = [&](int x, int y, int c) { a[x][y] = c; };
    Get_ans(i, 0, Check);
    int x = flag;
    flag = 1;
    Get_ans(i, 1, Check);
    int y = flag;
    if (x + y == 0) return (void)(ans = 0);
    if (x + y == 2) ans = 2;
    Get_ans(i, y, Cover);
  }
}
void work() { Get_ans(); }
void outo() {
  if (!ans)
    puts("NONE");
  else if (ans == 2)
    puts("MULTIPLE");
  else {
    puts("UNIQUE");
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) putchar(a[i][j] ? 'S' : 'G');
      puts("");
    }
  }
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
