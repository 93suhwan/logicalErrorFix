#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
int n, m, nxt[1000005], ban[1000005];
int main() {
  scanf("%d%d", &n, &m);
  char s[n + 5][m + 5];
  bool a[n + 5][m + 5];
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; ++i)
    if (s[i][1] == '.') a[i][1] = 1;
  for (int i = 1; i <= m; ++i)
    if (s[1][i] == '.') a[1][i] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (s[i][j] == 'X') continue;
      if ((a[i - 1][j] == 1 || a[i][j - 1] == 1)) {
        a[i][j] = 1;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (!a[i - 1][j] && !a[i][j - 1]) ban[j] = 1;
    }
  }
  int cur = m + 1;
  nxt[m + 1] = inf;
  for (int i = m; i; --i) {
    if (ban[i]) cur = i;
    nxt[i] = cur;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x + 1 <= y && nxt[x + 1] <= y)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
