#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
template <typename T>
void write(T t) {
  if (t < 0) {
    putchar('-');
    write(-t);
    return;
  }
  if (t > 9) write(t / 10);
  putchar('0' + t % 10);
}
template <typename T>
void writeln(T t) {
  write(t);
  puts("");
}
const int maxn = 2000 * 2000 + 10;
int n, tot;
vector<int> g[maxn], h[maxn];
char s[2010][2010];
int num[2010][2010], d[maxn];
int lst;
bool vis[maxn];
void merge(int x) {
  g[x].push_back(lst), g[lst].push_back(x);
  lst = x;
}
void link(int x, int y) { h[x].push_back(y), h[y].push_back(x); }
void No() {
  puts("NONE");
  exit(0);
}
void dfs(int x) {
  vis[x] = 1;
  for (int y : h[x]) {
    if (d[x] != d[y]) No();
    if (!vis[y]) d[y] = d[x], dfs(y);
  }
  for (int y : g[x]) {
    if (d[x] == d[y]) No();
    if (!vis[y]) d[y] = 3 - d[x], dfs(y);
  }
}
int main() {
  read(n);
  if (n & 1) No();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= n; j++)
      num[i][j] = ++tot, d[tot] = (s[i][j] == '.' ? 0 : s[i][j] == 'S' ? 1 : 2);
  }
  for (int i = 1; i <= n; i += 2) {
    int x = 1, y = i;
    lst = num[1][i];
    link(lst, num[1][i + 1]);
    while (y > 1 && x < n) {
      x++, y--;
      merge(num[x][y]);
    }
    link(num[x][y], num[x + 1][y]);
    lst = num[x + 1][y];
    x++;
    while (x < n && y < n) {
      x++, y++;
      merge(num[x][y]);
    }
    link(num[x][y], num[x][y + 1]);
    lst = num[x][y + 1];
    y++;
    while (x > 1 && y < n) {
      x--, y++;
      merge(num[x][y]);
    }
    lst = num[x - 1][y];
    x--;
    while (x > 1 && y > 1) {
      x--, y--;
      merge(num[x][y]);
    }
  }
  for (int i = 1; i <= tot; i++)
    if (!vis[i] && d[i]) dfs(i);
  for (int i = 1; i <= tot; i++)
    if (!d[i]) {
      puts("MULTIPLE");
      return 0;
    }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar(d[num[i][j]] == 1 ? 'S' : 'G');
    puts("");
  }
  return 0;
}
