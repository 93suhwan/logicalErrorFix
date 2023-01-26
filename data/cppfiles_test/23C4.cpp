#include <bits/stdc++.h>
using namespace std;
long long a[4005], v[4005 * 2];
int m;
vector<long long> f[4005 * 2];
int cnt[4005 * 2], tot;
int son[4005 * 2][2];
void Max(long long &x, long long y) {
  if (y > x) x = y;
}
void solve(int l, int r, int &rt) {
  rt = ++tot;
  f[rt].push_back(0);
  for (int i = l; i <= r; i++) f[rt].push_back(0);
  if (l > r) {
    return;
  }
  if (l == r) {
    v[rt] = a[l];
    cnt[rt] = 1;
    return;
  }
  int mx = a[l], id = l;
  for (int i = l; i <= r; i++) {
    if (a[i] < mx) {
      id = i;
      mx = a[i];
    }
  }
  v[rt] = mx;
  solve(l, id - 1, son[rt][0]);
  solve(id + 1, r, son[rt][1]);
  for (int i = 0; i <= cnt[son[rt][0]]; i++) {
    for (int j = 0; j <= cnt[son[rt][1]]; j++) {
      Max(f[rt][i + j],
          f[son[rt][0]][i] + (v[son[rt][0]] - v[rt]) * (i) * (m - i) +
              f[son[rt][1]][j] + (v[son[rt][1]] - v[rt]) * j * (m - j));
      Max(f[rt][i + j + 1],
          f[son[rt][0]][i] + (v[son[rt][0]] - v[rt]) * (i) * (m - i) +
              f[son[rt][1]][j] + (v[son[rt][1]] - v[rt]) * j * (m - j));
    }
  }
  cnt[rt] = cnt[son[rt][0]] + cnt[son[rt][1]] + 1;
}
int main() {
  int n;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  int rt = 0;
  solve(1, n, rt);
  printf("%lld\n", f[rt][m]);
  return 0;
}
