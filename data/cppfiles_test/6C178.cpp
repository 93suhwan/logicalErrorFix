#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const double eps = 1e-6;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
int cnt[N], sum;
int t, n, m;
int u, v, opt;
signed main() {
  n = read();
  m = read();
  for (int i = 0; i < m; i++) {
    u = read();
    v = read();
    cnt[min(u, v)] += 1;
    if (cnt[min(u, v)] == 1) sum++;
  }
  t = read();
  while (t--) {
    opt = read();
    if (opt == 1) {
      u = read();
      v = read();
      cnt[min(u, v)] += 1;
      if (cnt[min(u, v)] == 1) sum++;
    } else if (opt == 2) {
      u = read();
      v = read();
      cnt[min(u, v)] -= 1;
      if (cnt[min(u, v)] == 0) sum--;
    } else
      printf("%d\n", n - sum);
  }
}
