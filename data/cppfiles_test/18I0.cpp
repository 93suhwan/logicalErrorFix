#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -f;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
inline void chkmin(int &a, int b) {
  if (a > b) a = b;
}
inline void chkmax(int &a, int b) {
  if (a < b) a = b;
}
const int N = 1e6 + 5;
int n, f[N];
inline bool check() {
  for (int i = 0; i < n; i++)
    if (f[i] == 2e9) return false;
  return true;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    int d = read();
    for (int i = 0, x; i < n; i++) x = read(), f[i] = (x == 0) ? 0 : 2e9;
    int tmp = 0;
    while (!check()) {
      for (int i = 0; i < n; i++)
        if (f[i] != 2e9) f[(i + d) % n] = min(f[i] + 1, f[(i + d) % n]);
      ++tmp;
      if (tmp > 15) break;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, f[i]);
    if (ans == 2e9) ans = -1;
    printf("%d\n", ans);
  }
}
