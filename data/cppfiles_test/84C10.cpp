#include <bits/stdc++.h>
const int nn = 1e5 + 5;
const long long inf = 1e12;
int phi[nn];
void init() {
  for (int i = 1; i <= 100000; i++) phi[i] = i;
  for (int i = 2; i <= 100000; i++)
    if (phi[i] == i)
      for (int j = i; j <= 100000; j += i) phi[j] -= phi[j] / i;
}
long long a[nn];
long long c(int l, int r) {
  if (l > r) return inf;
  long long ret = 0;
  for (int i = l, val; i <= r; i = val + 1) {
    val = r / (r / i);
    int x = 0;
    if (i >= l)
      x = val - i + 1;
    else if (val >= l)
      x = val - l + 1;
    ret += a[r / i] * x;
  }
  return ret;
}
long long f[nn][17];
void solve(int p, int l, int r, int ql, int qr) {
  if (l > r) return;
  int mid = l + r >> 1;
  f[mid][p] = inf;
  int qmid = ql;
  long long cost = c(std::min(mid, qr) + 1, mid);
  for (int k = std::min(mid, qr); k >= ql; k--) {
    long long cc = f[k][p - 1] + cost;
    if (cc <= f[mid][p]) {
      f[mid][p] = cc;
      qmid = k;
    }
    if (k <= mid) {
      if (cost == inf)
        cost = a[mid / k];
      else
        cost += a[mid / k];
    }
  }
  solve(p, l, mid - 1, ql, qmid);
  solve(p, mid + 1, r, qmid, qr);
}
int main() {
  init();
  for (int i = 1; i <= 100000; i++) a[i] = a[i - 1] + phi[i];
  f[0][0] = 0;
  for (int i = 1; i <= 100000; i++) {
    f[i][0] = inf;
    f[i][1] = i * (i + 1ll) / 2;
  }
  for (int i = 2; i < 17; i++) solve(i, 1, 100000, 1, 100000);
  int t, n, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    if (k >= 17 || (1 << k) > n)
      printf("%d\n", n);
    else
      printf("%lld\n", f[n][k]);
  }
}
