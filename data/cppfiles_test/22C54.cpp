#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - 48;
    c = getchar();
  }
  return flag ? x : -x;
}
const int sqN = 5e2;
const int N = 2e5 + 7;
int f[sqN][sqN], lt[N], q[N], tag[N];
int x[N], y[N];
int main() {
  int n = read(), m = read();
  int sq = (int)(sqrt(m) + 0.5);
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (int i = 1; i <= m; i++) {
    int op = read();
    q[i] = read();
    int w = x[q[i]] + y[q[i]];
    if (w > sq) {
      if (op == 1)
        lt[q[i]] = i;
      else {
        for (int j = lt[q[i]] + x[q[i]]; j <= i; j += w)
          tag[j]++, tag[min(i, j + y[q[i]])]--;
        lt[q[i]] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (lt[i]) {
      int w = x[i] + y[i];
      for (int j = lt[i] + x[i]; j <= m; j += w)
        tag[j]++, tag[min(m + 1, j + y[i])]--;
    }
  int now = 0;
  for (int i = 1; i <= m; i++) {
    int w = x[q[i]] + y[q[i]];
    now += tag[i];
    if (w <= sq) {
      if (!lt[q[i]]) {
        for (int j = x[q[i]]; j < w; j++) f[w][(i + j) % w]++;
        lt[q[i]] = i;
      } else {
        for (int j = x[q[i]]; j < w; j++) f[w][(lt[q[i]] + j) % w]--;
        lt[q[i]] = 0;
      }
    }
    int ans = now;
    for (int j = 1; j <= sq; j++) ans += f[j][i % j];
    printf("%d\n", ans);
  }
}
