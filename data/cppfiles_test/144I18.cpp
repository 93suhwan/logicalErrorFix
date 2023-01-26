#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  return x * f;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + 48);
}
inline void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  out(x), puts("");
}
const int N = 2e5 + 10;
bool vis[N];
void solve() {
  int n = read(), m = read(), k = read(), a = n / m, b = (n + 1) / m, p = n % m,
      cnt = 0;
  for (int i = 1, cnt = 1, tot = 0; i <= k; i++, tot = 0) {
    for (int j = 1; j <= p; j++) {
      printf("\n%d ", b);
      for (int k = 1; k <= b; k++)
        printf("%d ", cnt), vis[cnt] = 1, cnt = cnt % n + 1;
    }
    for (int j = 1; j <= n; j++)
      if (vis[j])
        vis[j] = 0;
      else {
        if (tot % a)
          putchar(' ');
        else
          printf("\n%d ", a);
        printf("%d", j), tot++;
      }
  }
  puts("");
}
int main() {
  int T = read();
  while (T--) solve();
}
