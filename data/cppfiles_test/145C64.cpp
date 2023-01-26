#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
struct Q {
  int p, id;
  Q(int a, int b) : p(a), id(b) {}
  bool operator<(const Q &o) const { return p < o.p; }
};
vector<Q> c[N], d[N];
int x[N], y[N], t[N], f[N], lx[N], ly[N], mn[N];
int getf(int x) { return x == f[x] ? x : f[x] = getf(f[x]); }
void uni(int x, int y) { f[getf(x)] = getf(y); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, i, j;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (i = 1; i <= n; i++)
      cin >> x[i] >> y[i] >> t[i], a[i - 1] = x[i], b[i - 1] = y[i];
    sort((a).begin(), (a).end());
    sort((b).begin(), (b).end());
    a.resize(unique((a).begin(), (a).end()) - a.begin());
    b.resize(unique((b).begin(), (b).end()) - b.begin());
    int q1 = a.size();
    for (i = 0; i < q1; i++) c[i].erase((c[i]).begin(), (c[i]).end());
    int q2 = b.size();
    for (i = 0; i < q2; i++) d[i].erase((d[i]).begin(), (d[i]).end());
    for (i = 1; i <= n; i++)
      lx[i] = lower_bound((a).begin(), (a).end(), x[i]) - a.begin();
    for (i = 1; i <= n; i++)
      ly[i] = lower_bound((b).begin(), (b).end(), y[i]) - b.begin();
    for (i = 1; i <= n; i++)
      c[lx[i]].emplace_back(y[i], i), d[ly[i]].emplace_back(x[i], i);
    iota(f + 1, f + n + 1, 1);
    for (i = 0; i < q1; i++)
      if (c[i].size()) {
        int n = c[i].size();
        sort((c[i]).begin(), (c[i]).end());
        for (j = 1; j < n; j++)
          if (c[i][j].p - c[i][j - 1].p <= m) uni(c[i][j].id, c[i][j - 1].id);
      }
    for (i = 0; i < q2; i++)
      if (d[i].size()) {
        int n = d[i].size();
        sort((d[i]).begin(), (d[i]).end());
        for (j = 1; j < n; j++)
          if (d[i][j].p - d[i][j - 1].p <= m) uni(d[i][j].id, d[i][j - 1].id);
      }
    memset(mn + 1, 0x3f, n * sizeof mn[0]);
    for (i = 1; i <= n; i++) getf(i), mn[f[i]] = min(mn[f[i]], t[i]);
    vector<int> v;
    for (i = 1; i <= n; i++)
      if (f[i] == i) v.push_back(mn[i]);
    sort((v).begin(), (v).end());
    reverse((v).begin(), (v).end());
    for (i = 0; i + 1 < v.size(); i++)
      if (i >= v[i + 1]) break;
    cout << i << '\n';
  }
}
