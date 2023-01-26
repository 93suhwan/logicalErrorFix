#include <bits/stdc++.h>
using namespace std;
int a[15], n, ans;
int b[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int f[20];
void dfs(int x, int sum) {
  if (x <= n - 2) {
    if (x == n - 3 && a[n - 1] == 0)
      dfs(x + 1, sum * b[a[x]]);
    else {
      a[x + 2]--;
      if (a[x + 2] < 0) a[x + 2] += 10, f[x + 2] = 1;
      if (!f[x])
        dfs(x + 1, sum * b[a[x] + 10]);
      else
        dfs(x + 1, sum * b[a[x]]);
      a[x + 2]++;
      if (a[x + 2] > 9) a[x + 2] -= 10, f[x + 2] = 0;
      if (!f[x]) dfs(x + 1, sum * b[a[x]]);
    }
  } else {
    sum *= b[a[n]] * b[a[n - 1]];
    ans += sum;
    return;
  }
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
int main() {
  int t = read();
  while (t--) {
    n = 0, ans = 0;
    memset(f, 0, sizeof f);
    int x = read();
    while (x) a[++n] = x % 10, x /= 10;
    dfs(1, 1);
    printf("%d\n", ans - 2);
  }
  return 0;
}
