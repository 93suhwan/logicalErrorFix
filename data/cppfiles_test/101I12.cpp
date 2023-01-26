#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxn = 200010;
int n, T, x[maxn], y[maxn], m, k, c[300010], d[300010], cnt, pos;
int sum, a[maxn], b[maxn];
map<int, int> px, py;
map<int, map<int, int> > mpx, mpy;
long long ans;
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    px.clear();
    py.clear();
    mpx.clear();
    mpy.clear();
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i]);
      a[i] = 0;
      px[x[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &y[i]);
      b[i] = 0;
      py[y[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
      scanf("%d", &c[i]);
      scanf("%d", &d[i]);
      if (px[c[i]] && py[d[i]]) continue;
      if (px[c[i]] && !py[d[i]]) {
        pos = lower_bound(y + 1, y + m + 1, d[i]) - y;
        a[pos]++;
        mpx[px[c[i]]][pos]++;
      } else if (!px[c[i]] && py[d[i]]) {
        pos = lower_bound(x + 1, x + n + 1, c[i]) - x;
        b[pos]++;
        mpy[pos][py[d[i]]]++;
      }
    }
    for (int i = 1; i <= k; i++) {
      if (px[c[i]] && py[d[i]]) continue;
      if (px[c[i]] && !py[d[i]]) {
        pos = lower_bound(y + 1, y + m + 1, d[i]) - y;
        if (a[pos] > mpx[px[c[i]]][pos]) ans += a[pos] - mpx[px[c[i]]][pos];
      } else if (!px[c[i]] && py[d[i]]) {
        pos = lower_bound(x + 1, x + n + 1, c[i]) - x;
        if (b[pos] > mpy[pos][py[d[i]]]) ans += b[pos] - mpy[pos][py[d[i]]];
      }
    }
    printf("%lld\n", ans / 2);
  }
}
