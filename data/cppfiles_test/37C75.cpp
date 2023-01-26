#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
bool vis[maxn];
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == 45) y = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * y;
}
int main() {
  int T;
  T = read();
  while (T--) {
    int n, m;
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      a = read();
      b = read();
      c = read();
      vis[b] = 1;
    }
    int rt = 0;
    for (int i = 1; i <= n; i++)
      if (!vis[i]) rt = i;
    for (int i = 1; i <= n; i++)
      if (i ^ rt) printf("%d %d\n", rt, i);
  }
  return 0;
}
