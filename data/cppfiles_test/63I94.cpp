#include <bits/stdc++.h>
using namespace std;
int t = 1, n, m, k, q, l, r, ans, a[29], mn[29], cnt[29][800009], b, c, u, v, x,
    y, z, qwq[1 << 20], sum[1 << 20], f[1 << 20][21], vis[1 << 20][21],
    mod = 1e9 + 7;
string s[29];
struct st {
  int x, y;
};
bool cmp(const st &a, const st &b) { return a.x < b.x; }
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
int qp(int x, int y) {
  int a = 1, b = x;
  while (y) {
    if (y & 1) a = a * b % mod;
    b = b * b % mod, y >>= 1;
  }
  return a;
}
int main() {
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i += 1) {
      cin >> s[i];
      for (int j = 0; j < s[i].length(); j += 1) {
        a[i] += s[i][j] == '(' ? 1 : -1, mn[i] = min(mn[i], a[i]);
        if (mn[i] == a[i]) cnt[i][a[i] + 400001] += 1;
      }
    }
    for (int i = 0; i < (1 << n); i += 1)
      for (int j = 1; j <= n; j += 1)
        if (i & (1 << j - 1)) sum[i] += a[j], qwq[i] += 1;
    for (int i = 1; i < (1 << n); i += 1)
      if (qwq[i] == 1) {
        for (int j = 1; j <= n; j += 1)
          if (i & (1 << j - 1)) {
            if (mn[j] < 0)
              vis[i][j] = 1, ans = max(ans, cnt[i][400001]);
            else
              f[i][j] = cnt[i][400001], ans = max(ans, f[i][j]);
          }
      }
    for (int i = 2; i < (1 << n); i += 1)
      if (qwq[i] > 1) {
        for (int j = 1; j <= n; j += 1)
          if (i & (1 << j - 1)) {
            int sts = (i ^ (1 << j - 1));
            bool wtf = 0;
            for (int k = 1; k <= n; k += 1)
              if (!vis[sts][k] && (sts & (1 << k - 1))) {
                if (sum[sts] + mn[j] < 0)
                  ans = max(ans, f[sts][k] + cnt[j][-sum[sts] + 400001]);
                else
                  wtf = 1,
                  f[i][j] =
                      max(f[i][j], f[sts][k] + cnt[j][-sum[sts] + 400001]),
                  ans = max(ans, f[i][j]);
              }
            if (!wtf) vis[i][j] = 1;
          }
      }
    printf("%lld", ans);
  }
  return 0;
}
