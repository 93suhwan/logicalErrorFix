#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
int x[200010], y[200010];
bool visx[1000005], visy[1000005];
int qx[1000010], qy[1000010], num;
vector<int> px[1000005], py[1000005];
bool sx[1000005], sy[1000005];
int numx[1000005], numy[1000005];
int xx[300010], yy[300010];
struct Point {
  int x, y;
} p[1000010];
int lsh[1000010], all;
int main() {
  scanf("%d", &T);
  while (T--) {
    all = 0;
    num = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]), lsh[++all] = x[i];
    for (int i = 1; i <= m; i++) scanf("%d", &y[i]), lsh[++all] = y[i];
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + m);
    for (int i = 1; i <= k; i++)
      scanf("%d%d", &xx[i], &yy[i]), lsh[++all] = xx[i], lsh[++all] = yy[i];
    sort(lsh + 1, lsh + 1 + all);
    all = unique(lsh + 1, lsh + 1 + all) - lsh - 1;
    for (int i = 1; i <= n; i++)
      x[i] = lower_bound(lsh + 1, lsh + 1 + all, x[i]) - lsh, visx[x[i]] = 1;
    for (int i = 1; i <= m; i++)
      y[i] = lower_bound(lsh + 1, lsh + 1 + all, y[i]) - lsh, visy[y[i]] = 1;
    int cntx = 0, cnty = 0;
    for (int i = 1; i <= k; i++) {
      xx[i] = lower_bound(lsh + 1, lsh + 1 + all, xx[i]) - lsh;
      yy[i] = lower_bound(lsh + 1, lsh + 1 + all, yy[i]) - lsh;
      if (visx[xx[i]] && visy[yy[i]]) continue;
      num++;
      p[num].x = xx[i], p[num].y = yy[i];
      if (visx[xx[i]]) {
        px[xx[i]].push_back(yy[i]);
        numx[yy[i]]++;
      } else if (visy[yy[i]]) {
        py[yy[i]].push_back(xx[i]);
        numy[xx[i]]++;
      }
    }
    for (int i = 1; i <= all; i++) numx[i] += numx[i - 1];
    for (int i = 1; i <= all; i++) numy[i] += numy[i - 1];
    for (int i = 1; i <= num; i++) {
      if (!sx[p[i].x] && px[p[i].x].size())
        sort(px[p[i].x].begin(), px[p[i].x].end()), sx[p[i].x] = 1;
      if (!sy[p[i].y] && py[p[i].y].size())
        sort(py[p[i].y].begin(), py[p[i].y].end()), sy[p[i].y] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= num; i++) {
      if (visx[p[i].x]) {
        int r = upper_bound(y + 1, y + 1 + m, p[i].y) - y;
        int l = y[r - 1];
        r = y[r];
        ans += numx[r] - numx[l - 1];
        l = lower_bound(px[p[i].x].begin(), px[p[i].x].end(), l) -
            px[p[i].x].begin();
        r = upper_bound(px[p[i].x].begin(), px[p[i].x].end(), r) -
            px[p[i].x].begin() - 1;
        ans -= r - l + 1;
      } else {
        int r = upper_bound(x + 1, x + 1 + n, p[i].x) - x;
        int l = x[r - 1];
        r = x[r];
        ans += numy[r] - numy[l - 1];
        l = lower_bound(py[p[i].y].begin(), py[p[i].y].end(), l) -
            py[p[i].y].begin();
        r = upper_bound(py[p[i].y].begin(), py[p[i].y].end(), r) -
            py[p[i].y].begin() - 1;
        ans -= r - l + 1;
      }
    }
    printf("%lld\n", ans / 2);
    for (int i = 1; i <= all; i++) numx[i] = numy[i] = 0;
    for (int i = 1; i <= n; i++) visx[x[i]] = 0;
    for (int i = 1; i <= m; i++) visy[y[i]] = 0;
    for (int i = 1; i <= num; i++) {
      sx[p[i].x] = sy[p[i].y] = 0;
      px[p[i].x].clear();
      py[p[i].y].clear();
    }
  }
}
