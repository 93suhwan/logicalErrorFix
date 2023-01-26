#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
const int N = 2005;
int n, f[N], fa[N], gx[N];
char g[N][N];
pair<int, int> e[N][N];
int main() {
  memset(f, -1, sizeof f);
  read(n);
  for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
  if (n & 1) {
    puts("NONE");
    return 0;
  }
  for (int i = 1; i <= n / 2; i++) {
    e[i][i].first = i;
    if (i > 1) e[i][i - 1] = make_pair(1, i & 1);
  }
  int c = 1;
  for (int i = 1; i <= n / 2; i++) {
    e[i][1] = make_pair(c, (c % 2 == 0));
    if (i % 2 == 0) ++c;
  }
  for (int i = 2; i <= n / 2; i++) {
    for (int j = 2; j + 1 < i; j++) {
      if (e[i - 1][j - 1].first == e[i - 2][j].first) {
        e[i][j] = e[i - 1][j + 1];
        e[i][j].second ^= 1;
      } else {
        e[i][j] = e[i - 1][j - 1];
        e[i][j].second ^= 1;
      }
    }
  }
  int st = ((n / 2) & 1) + 1;
  for (int i = 1; i <= n / 2; i++) fa[i] = i;
  for (int i = st; i <= n / 2; i += 2) {
    fa[e[n / 2][i].first] = e[n / 2][i + 1].first;
    gx[e[n / 2][i].first] = e[n / 2][i].second ^ e[n / 2][i + 1].second ^ 1;
  }
  for (int i = 1; i <= n / 2; i++)
    for (int j = 1; j < i; j++) e[j][i] = e[i][j];
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= n / 2; j++) {
      e[n - i + 1][j] = e[i][n - j + 1] = e[n - i + 1][n - j + 1] = e[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (g[i][j] != '.') {
        int v = g[i][j] == 'S';
        pair<int, int> t = e[i][j];
        if (f[fa[t.first]] != -1 &&
            f[fa[t.first]] != (v ^ t.second ^ gx[t.first])) {
          puts("NONE");
          return 0;
        }
        f[fa[t.first]] = v ^ t.second ^ gx[t.first];
      }
    }
  }
  for (int i = 1; i <= n / 2; i++) {
    if (fa[i] == i && f[i] == -1) {
      puts("MULTIPLE");
      return 0;
    }
  }
  puts("UNIQUE");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      pair<int, int> t = e[i][j];
      int v = f[fa[t.first]] ^ t.second ^ gx[t.first];
      char c = v ? 'S' : 'G';
      putchar(c);
    }
    puts("");
  }
  return 0;
}
