#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], p[N], ansa[N], ansb[N], c[2 * N], d[2 * N];
long long e[2 * N];
int k;
void add(int x, int y) {
  for (; x <= k; x += x & -x) e[x] += y;
}
long long ask(int x) {
  long long ans = 0;
  for (; x; x -= x & -x) ans += e[x];
  return ans;
}
void solve(int li, int ri, int lp, int rp) {
  if (li > ri) return;
  int mid = (li + ri) / 2;
  ansa[lp - 1] = 0;
  for (int i = lp; i <= rp; i++)
    if (b[mid] < a[i])
      ansa[i] = ansa[i - 1] + 1;
    else
      ansa[i] = ansa[i - 1];
  ansb[rp + 1] = 0;
  for (int i = rp; i >= lp; i--)
    if (b[mid] > a[i])
      ansb[i] = ansb[i + 1] + 1;
    else
      ansb[i] = ansb[i + 1];
  int maxx = 1e9, k;
  for (int i = lp; i <= rp; i++)
    if (ansa[i - 1] + ansb[i] < maxx) maxx = ansa[i - 1] + ansb[i], k = i;
  p[mid] = k;
  solve(li, mid - 1, lp, k);
  solve(mid + 1, ri, k, rp);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m);
    solve(1, m, 1, n + 1);
    int t = 1;
    k = 0;
    for (int i = 1; i <= n + 1; i++) {
      while (t <= m && p[t] == i) c[++k] = b[t], t++;
      if (i != n + 1) c[++k] = a[i];
    }
    for (int i = 1; i <= k; i++) d[i] = c[i];
    sort(d + 1, d + 1 + k);
    int tot = unique(d + 1, d + 1 + k) - d - 1;
    for (int i = 1; i <= k; i++)
      c[i] = lower_bound(d + 1, d + 1 + tot, c[i]) - d;
    for (int i = 0; i <= k; i++) e[i] = 0;
    long long sum = 0;
    for (int i = k; i >= 1; i--) {
      sum += ask(c[i] - 1);
      add(c[i], 1);
    }
    printf("%lld\n", sum);
  }
  return 0;
}
