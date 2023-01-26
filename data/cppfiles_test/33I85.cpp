#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fh = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fh;
}
inline void out(int *a, int l, int r) {
  for (int i = l; i <= r; ++i) printf("%d ", *(a + i));
  puts("");
}
const int N = 1e5 + 5, inf = 1e9;
int a[N], b[N], n, ok[N];
bool f[N][550];
signed main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 0; i <= 1024; ++i) b[i] = inf;
  ok[0] = 1, b[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 512; ++j) f[i][j] = b[j ^ a[i]] < a[i];
    for (int j = 0; j <= 512; ++j)
      if (f[i][j]) (b[j] = min(b[j], a[i])), ok[j] = 1;
  }
  for (int i = 0; i <= 512; ++i)
    if (ok[i]) printf("%d ", i);
  return 0;
}
