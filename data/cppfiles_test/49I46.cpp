#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1123;
const int mod = 998244353;
int n;
int a[N];
int t[N * 4], cnt[N], res[N];
vector<int> g[N];
set<int> at[N];
vector<pair<pair<int, int>, int> > req[N];
void upd(int v, int tl, int tr, int pos, long long new_val) {
  if (tl == tr)
    t[v] += new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      upd(v * 2, tl, tm, pos, new_val);
    else
      upd(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = (t[v * 2] + t[v * 2 + 1]);
  }
}
long long get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return (get(v * 2, tl, tm, l, min(r, tm)) +
          get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
long long ret(int v, int tl, int tr, int l, int leftval, int k, int kek = 0) {
  if (tl == tr) {
    if (t[v] - leftval >= k)
      return tl;
    else
      return 0;
  }
  int tm = (tl + tr) / 2;
  int sl = max(tl, 1);
  int sr = min(tr, l);
  int z = get(1, 1, n, sl, sr);
  if (t[v + v] - leftval >= k)
    return ret(v + v, tl, tm, l, leftval, k, kek);
  else
    return ret(v + v + 1, tm + 1, tr, l, leftval, k + t[v + v] - z * 2, kek);
}
void dfs(int u) {
  int cu = cnt[a[u]];
  if (cu > 0) {
    upd(1, 1, n, cu, -1);
    at[cu].erase(a[u]);
  }
  cnt[a[u]]++;
  cu = cnt[a[u]];
  upd(1, 1, n, cu, 1);
  at[cu].insert(a[u]);
  for (int i = 0; i < req[u].size(); i++) {
    pair<pair<int, int>, int> tmp = req[u][i];
    int l = tmp.first.first;
    int k = tmp.first.second;
    int id = tmp.second;
    int lefval = get(1, 1, n, 1, l - 1);
    int qq = 0;
    int pos = ret(1, 1, n, l - 1, lefval, k, qq);
    if (pos < 1) {
      res[id] = -1;
    } else {
      res[id] = (*at[pos].begin());
    }
  }
  for (auto to : g[u]) {
    dfs(to);
  }
  upd(1, 1, n, cu, -1);
  at[cu].erase(a[u]);
  cnt[a[u]]--;
  cu = cnt[a[u]];
  if (cu > 0) {
    upd(1, 1, n, cu, 1);
    at[cu].insert(a[u]);
  }
}
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i <= (n + 100) * 4; i++) t[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[i] = 0;
    at[i].clear();
    g[i].clear();
    req[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    int v, l, k;
    cin >> v >> l >> k;
    req[v].push_back(make_pair(make_pair(l, k), i));
  }
  dfs(1);
  for (int i = 1; i <= q; i++) cout << res[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(NULL));
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
