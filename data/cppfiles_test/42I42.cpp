#include <bits/stdc++.h>
using namespace std;
int n, x, y, lim, ans, t;
const int N = 2e5 + 5;
int f[N * 2], a[N * 2], q[N], v[N * 2];
bool b[N * 2];
const int mo = 1e9 + 7;
int ask(int x) {
  int ans = 0;
  while (x) {
    ans = (ans + f[x]) % mo;
    x -= x & (-x);
  }
  return ans;
}
void ins(int x, int y) {
  while (x <= 2 * n) {
    f[x] = (f[x] + y) % mo;
    x += x & (-x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    a[x] = y;
    a[y] = x;
    q[i] = x;
  }
  for (int i = 2 * n; i >= 1; i--)
    if (a[i] > i) {
      v[i] = ask(a[i]) + 1;
      ins(a[i], v[i]);
    }
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &x);
    b[q[x]] = true;
  }
  lim = 0;
  for (int i = 2 * n; i >= 1; i--)
    if (a[i] > i) {
      if (a[i] < lim || b[i]) ans = (ans + v[i]) % mo;
      if (b[i]) lim = a[i];
    }
  printf("%d\n", ans);
}
