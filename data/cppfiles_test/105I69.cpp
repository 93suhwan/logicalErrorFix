#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 998244353, INF = 1e9 + 7;
const long long BIG = 1e18;
const int block = 316;
const int base = 1000000000;
const int base_digits = 9;
const int tox[] = {0, 0, 1, -1}, toy[] = {1, -1, 0, 0};
int n, a[N], b[N], m[N], bp[N], d[N], u[N * 4], xi[N];
pair<int, int> t[N * 4];
vector<pair<int, int> > vec[N];
bool was[N];
void clear() {
  for (int i = 1; i <= n; i++) {
    vec[d[i]].clear();
    was[d[i]] = 0;
  }
}
void build(int v, int l, int r) {
  if (l == r) {
    t[v] = {0, l};
    return;
  }
  int tm = (l + r) / 2;
  build(v + v, l, tm);
  build(v + v + 1, tm + 1, r);
  t[v] = max(t[v + v], t[v + v + 1]);
}
void push(int v) {
  u[v + v] += u[v];
  u[v + v + 1] += u[v];
  t[v + v].first += u[v];
  t[v + v + 1].first += u[v];
  u[v] = 0;
}
void update(int v, int l, int r, int x, int y, int val) {
  if (x > r or l > y) return;
  if (x <= l and r <= y) {
    t[v].first += val;
    u[v] += val;
    return;
  }
  int tm = (l + r) / 2;
  push(v);
  update(v + v, l, tm, x, y, val);
  update(v + v + 1, tm + 1, r, x, y, val);
  t[v] = max(t[v + v], t[v + v + 1]);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> m[i];
    bp[i] = b[i] - m[i];
    d[i] = bp[i] + a[i];
    int r = a[i] - max(0, m[i] - b[i]);
    int l = a[i] - min(m[i], a[i]);
    vec[d[i]].push_back({l, r});
  }
  int lim = 1e6 + 5;
  int ans = 0;
  for (int j = 1; j <= n; j++) {
    int i = d[j];
    if (was[i]) continue;
    was[i] = 1;
    for (auto e : vec[i]) {
      int l = e.first;
      int r = e.second;
      update(1, 0, lim, l, r, 1);
    }
    int sz = (int)vec[i].size();
    ans += sz - t[1].first + 1;
    xi[i] = t[1].second;
    for (auto e : vec[i]) {
      int l = e.first;
      int r = e.second;
      update(1, 0, lim, l, r, -1);
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    int j = d[i];
    int yi = m[i] - (a[i] - xi[j]);
    if (a[i] >= xi[j] and b[i] >= yi and yi >= 0) {
      cout << a[i] - xi[j] << ' ' << yi << endl;
    } else {
      int x = max(0, m[i] - b[i]);
      int y = m[i] - x;
      cout << x << " " << y << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int lim = 1e6 + 5;
  build(1, 0, lim);
  int q;
  cin >> q;
  while (q--) {
    solve();
    clear();
  }
}
