#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, B = 1;
int n, q, k, m, a[N], mn[N][20], lg[N];
long long t0[N], t1[N], ans[N];
struct Qr {
  int l, r, id;
  friend bool operator<(Qr a, Qr b) { return a.l > b.l; }
};
int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
vector<Qr> qry[N];
void M(int x, int y) {
  ++x;
  for (int i = x; i <= m + 1; i += i & -i) t0[i] += y, t1[i] += 1ll * x * y;
}
long long Q(int x) {
  ++x;
  long long ret = 0;
  for (int i = x; i; i -= i & -i) ret += 1ll * (x + 1) * t0[i] - t1[i];
  return ret;
}
void M(int x, int y, int z) { M(x, z), M(y + 1, -z); }
long long Q(int x, int y) { return Q(y) - Q(x - 1); }
void solve(int x) {
  sort(qry[x].begin(), qry[x].end()), m = (n - x) / k;
  for (int i = 0; i <= m + 2; i++) t0[i] = t1[i] = 0;
  stack<Qr> st;
  for (int i = 0; i <= (int)qry[x].size() - 1; i++) {
    int pl = i ? qry[x][i - 1].l - 1 : m;
    for (int j = pl; j >= qry[x][i].l; j--) {
      if (j < m) {
        int t = query(k * j + x, k * j + x + k - 1), r = j - 1;
        while (!st.empty() && st.top().id > t)
          M(st.top().l, st.top().r, -st.top().id), r = st.top().r, st.pop();
        if (j + 1 <= r) M(j + 1, r, t), st.push({j + 1, r, t});
      }
      M(j, j, a[k * j + x]), st.push({j, j, a[k * j + x]});
    }
    ans[qry[x][i].id] = Q(qry[x][i].l, qry[x][i].r);
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
    scanf("%d%d", &l, &r), --l, --r;
    qry[l % k].push_back({l / k, l / k + (r - l) / k, i});
  }
  for (int i = 0; i <= k - 1; i++) solve(i);
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}
