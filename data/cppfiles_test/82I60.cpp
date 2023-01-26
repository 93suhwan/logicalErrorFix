#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, B = 1;
int n, q, k, a[N], mn[N][20], lg[N], ans[N];
struct Q {
  int l, r, id;
  friend bool operator<(Q a, Q b) { return a.l > b.l; }
};
int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
vector<Q> qry[N];
int v[N];
void solve(int x) {
  sort(qry[x].begin(), qry[x].end());
  memset(v, 0x3f, sizeof(v));
  for (int i = 0; i <= (int)qry[x].size() - 1; i++) {
    for (int j = qry[x][i].l; j <= (n - x) / k; j++)
      v[j] = query(qry[x][i].l * k + x, j * k + x);
    long long ret = 0;
    for (int j = qry[x][i].l; j <= qry[x][i].r; j++) ret += v[j];
    ans[qry[x][i].id] = ret;
  }
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 0; i <= n - 1; i++) mn[i][0] = a[i];
  for (int j = 1; j <= lg[n]; j++)
    for (int i = 0; i <= n - (1 << j); i++)
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    qry[l % k].push_back({l / k, r / k, i});
  }
  for (int i = 0; i <= k - 1; i++) solve(i);
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
