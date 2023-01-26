#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
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
void report(string info) {
  cout << info << '\n';
  exit(0);
}
const int N = 3005;
char s[N][N];
int n;
struct node {
  int x, y, c;
};
void sol(int t) {
  vector<node> qwq;
  int c0 = -1, c1 = -1;
  auto push = [&](int x, int y, int c) {
    qwq.push_back({x, y, c});
    if (!c && s[x][y] != '.') {
      if (c0 != -1 && c0 != (s[x][y] == 'S')) report("NONE");
      c0 = (s[x][y] == 'S');
    }
    if (c && s[x][y] != '.') {
      if (c1 != -1 && c1 != (s[x][y] == 'S')) report("NONE");
      c1 = (s[x][y] == 'S');
    }
  };
  int x = 2 * t, y = 1, c = 0;
  push(x, y, 0);
  push(--x, y, 0);
  while (x > 1) {
    x--, y++, c ^= 1;
    push(x, y, c);
  }
  push(x, ++y, c);
  while (y < n) {
    x++, y++, c ^= 1;
    push(x, y, c);
  }
  push(++x, y, c);
  while (x < n) {
    x++, y--, c ^= 1;
    push(x, y, c);
  }
  push(x, --y, c);
  while (y > 1) {
    x--, y--, c ^= 1;
    push(x, y, c);
  }
  assert(x == 2 * t && y == 1);
  if (c0 != -1 && c1 != -1 && c0 == c1) report("NONE");
  if (c0 == -1 && c1 == -1) report("MULTIPLE");
  if (c1 == -1) c1 = c0 ^ 1;
  if (c0 == -1) c0 = c1 ^ 1;
  for (auto [x, y, c] : qwq) {
    if (c == 0)
      s[x][y] = (c0 ? 'S' : 'G');
    else
      s[x][y] = (c1 ? 'S' : 'G');
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  if (n & 1) return puts("NONE"), 0;
  for (int t = 1; t <= n / 2; t++) {
    sol(t);
  }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++) {
    puts(s[i] + 1);
  }
  return 0;
}
