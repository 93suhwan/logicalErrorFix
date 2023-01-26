#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool op = false;
  char c = getchar();
  while (!isdigit(c)) op |= (c == '-'), c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 2e5 + 10;
int n, m, B;
int dif[N], d[500][500], lst[N];
struct Node {
  int x, y;
  Node() {}
  Node(int x, int y) : x(x), y(y) {}
} a[N];
int main() {
  n = read();
  m = read();
  B = sqrt(m);
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    a[i] = Node(x, y);
  }
  int ans = 0;
  for (int t = 1; t <= m; t++) {
    int op = read(), x = read();
    if (op == 1) {
      if (a[x].x + a[x].y > B) {
        for (int i = t + a[x].x; i <= m; i += a[x].x + a[x].y) {
          dif[i]++;
          if (i + a[x].y <= m) dif[i + a[x].y]--;
        }
      } else {
        int l = (t + a[x].x) % (a[x].x + a[x].y),
            r = (t - 1) % (a[x].x + a[x].y);
        if (l <= r)
          for (int i = l; i <= r; i++) d[a[x].x + a[x].y][i]++;
        else {
          for (int i = 0; i <= l; i++) d[a[x].x + a[x].y][i]++;
          for (int i = r; i < a[x].x + a[x].y; i++) d[a[x].x + a[x].y][i]++;
        }
      }
      lst[x] = t;
    } else {
      if (a[x].x + a[x].y > B) {
        for (int i = lst[x] + a[x].x; i <= m; i += a[x].x + a[x].y) {
          dif[i]--;
          if (i + a[x].y <= m) dif[i + a[x].y]++;
          if (i < t && i + a[x].y >= t) ans--;
        }
      } else {
        int l = (lst[x] + a[x].x) % (a[x].x + a[x].y),
            r = (lst[x] - 1) % (a[x].x + a[x].y);
        if (l <= r)
          for (int i = l; i <= r; i++) {
            d[a[x].x + a[x].y][i]--;
          }
        else {
          for (int i = 0; i <= l; i++) d[a[x].x + a[x].y][i]--;
          for (int i = r; i < a[x].x + a[x].y; i++) d[a[x].x + a[x].y][i]--;
        }
      }
      lst[x] = 0;
    }
    int res = 0;
    ans += dif[t];
    for (int i = 1; i <= B; i++) res += d[i][t % i];
    printf("%d\n", res + ans);
  }
}
