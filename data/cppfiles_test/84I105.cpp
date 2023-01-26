#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mx = 1e5, mod = 998244353;
int n, a[N], T, stk[N], nw[N], top, ret[N], L[N], R[N];
inline int dec(int x, int y) { return (x - y < 0) ? x - y + mod : x - y; }
inline void inc(int &x, int y) { x = (x + y >= mod) ? x + y - mod : x + y; }
int nxt[N][500];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]), L[i] = R[i] = a[i], nw[i] = 1;
    int ans = 0, now = 0;
    ;
    for (int r = 1; r <= n; ++r) {
      ret[r] = 0;
      int tmp = 0;
      inc(ans, now);
      for (int l = r - 1; l >= 1; --l) {
        if (R[l] > L[l + 1]) {
          while (R[l] > L[l + 1]) {
            int x = a[l] - 1, w = nw[l];
            nw[l] = x / (x / nw[l]) + 1;
            inc(tmp, nw[l] - w);
            L[l] = a[l] / nw[l];
            R[l] = (a[l] - 1) / nw[l] + 1;
          }
        } else {
          inc(now, 1ll * tmp * l % mod);
          inc(ans, 1ll * tmp * l % mod);
          break;
        }
        inc(ans, tmp);
        inc(now, tmp);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
