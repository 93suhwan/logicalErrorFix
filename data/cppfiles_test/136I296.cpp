#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; c != EOF && !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  if (c == EOF) return 0;
  for (; c != EOF && isdigit(c); c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
  return 1;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
const int N = 1e5;
int T, n, b[N], g[N], sum, ans[N], mn;
int main() {
  read(T);
  while (T--) {
    read(n);
    sum = 0;
    mn = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) read(b[i]);
    for (int i = 2; i <= n; ++i) sum += (g[i] = b[i] - b[i - 1]);
    sum += (g[1] = b[1] - b[n]);
    if (sum) goto FAIL;
    for (int i = 2; i <= n; ++i)
      if ((g[1] - g[i]) % n)
        goto FAIL;
      else
        ans[i] = (g[1] - g[i]) / n, mn = min(ans[i], mn);
    ans[1] = max(1, -mn + 1);
    if (ans[1] >= b[1]) goto FAIL;
    for (int i = 2; i <= n; ++i)
      if ((ans[i] += ans[1]) >= b[i] || ans[i] <= 0) goto FAIL;
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    puts("");
    continue;
  FAIL:
    puts("NO");
  }
  return 0;
}
