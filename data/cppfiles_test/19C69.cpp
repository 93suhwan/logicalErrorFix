#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2, N1 = maxn + 5, p = 1000000007;
template <typename _T>
void read(_T &ret) {
  ret = 0;
  _T fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  ret = ret * fh;
}
int T, n;
int a[N1], b[N1];
int check() {
  for (int s = 0; s < (1 << n); s++) {
    for (int t = s;; t = (t - 1) & s) {
      int now = 0;
      for (int i = 0; i < n; i++) {
        if (s & (1 << i)) {
          if (t & (1 << i))
            now += a[i];
          else
            now -= a[i];
        }
      }
      for (int i = 0; i < n; i++) {
        if (!(s & (1 << i)))
          if (abs(now) == a[i]) return 1;
      }
      if (!t) break;
    }
  }
  return 0;
}
void solve() {
  read(n);
  for (int i = 0; i < n; i++) read(a[i]), a[i] = abs(a[i]);
  int fl = check();
  if (fl)
    puts("YES");
  else
    puts("NO");
}
int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
