#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int res = 0, flag = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * flag;
}
int T, n, m, a[301], t[301], k, cnt[301], s[301], c[301], v[301];
inline void update(int x, int v) {
  for (; x <= m; x += ((x) & (-(x)))) c[x] += v;
}
inline int sum(int x) {
  int res = 0;
  for (; x; x -= ((x) & (-(x)))) res += c[x];
  return res;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    for (register int i = 1; i <= m; ++i) {
      t[i] = a[i] = read();
      cnt[i] = s[i] = v[i] = c[i] = 0;
    }
    sort(t + 1, t + m + 1);
    k = unique(t + 1, t + m + 1) - t - 1;
    for (register int i = 1; i <= m; ++i) {
      a[i] = lower_bound(t + 1, t + k + 1, a[i]) - t;
      ++cnt[a[i]];
    }
    for (register int i = 1; i <= k; ++i) s[i] = s[i - 1] + cnt[i];
    int ans = 0;
    for (register int i = 1; i <= m; ++i) {
      ans += sum(s[a[i] - 1]);
      update(s[a[i]] - v[a[i]], 1);
      ++v[a[i]];
    }
    printf("%d\n", ans);
  }
  return 0;
}
