#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
const int N = 1e6 + 10;
set<int> se[N];
vector<vector<int> > g(N);
int cnt[N], a[N], ans[N], sum[4 * N];
vector<vector<pair<int, pair<int, int> > > > req(N);
void build(int v, int l, int r) {
  if (l == r) {
    sum[v] = 0;
    return;
  }
  int mid = (r + l) / 2;
  build(2 * v, l, mid);
  build(2 * v + 1, mid + 1, r);
  sum[v] = 0;
}
void upd(int v, int l, int r, int pos, int val) {
  if (l > pos || r < pos) {
    return;
  }
  if (l == r) {
    sum[v] += val;
    return;
  }
  int mid = (r + l) / 2;
  upd(2 * v, l, mid, pos, val);
  upd(2 * v + 1, mid + 1, r, pos, val);
  sum[v] = sum[2 * v] + sum[2 * v + 1];
}
int get_sum(int v, int l, int r, int tl, int tr) {
  if (l > tr || r < tl) {
    return 0;
  }
  if (l >= tl && r <= tr) {
    return sum[v];
  }
  int mid = (r + l) / 2;
  return get_sum(2 * v, l, mid, tl, tr) +
         get_sum(2 * v + 1, mid + 1, r, tl, tr);
}
int n, row;
void get(int v, int l, int r, int k) {
  if (l == r) {
    row = l;
    return;
  }
  int mid = (r + l) / 2;
  if (sum[2 * v] >= k) {
    get(2 * v, l, mid, k);
  } else {
    get(2 * v + 1, mid + 1, r, k - sum[2 * v]);
  }
}
void dfs(int v, int pr) {
  if (cnt[a[v]] != 0) {
    upd(1, 1, n, cnt[a[v]], -1);
    se[cnt[a[v]]].erase(a[v]);
  }
  cnt[a[v]]++;
  se[cnt[a[v]]].insert(a[v]);
  upd(1, 1, n, cnt[a[v]], 1);
  for (int i = 0; i < req[v].size(); i++) {
    int pos = req[v][i].first, l = req[v][i].second.first,
        k = req[v][i].second.second;
    int val;
    if (l == 1) {
      val = 0;
    } else {
      val = get_sum(1, 1, n, 1, l - 1);
    }
    k += val;
    if (sum[1] < k) {
      ans[pos] = -1;
    } else {
      get(1, 1, n, k);
      ans[pos] = *se[row].begin();
    }
  }
  for (auto i : g[v]) {
    if (i == pr) {
      continue;
    }
    dfs(i, v);
  }
  se[cnt[a[v]]].erase(a[v]);
  upd(1, 1, n, cnt[a[v]], -1);
  cnt[a[v]]--;
  if (cnt[a[v]] != 0) {
    upd(1, 1, n, cnt[a[v]], 1);
    se[cnt[a[v]]].insert(a[v]);
  }
}
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].clear();
    cnt[a[i]] = 0;
    req[i].clear();
  }
  build(1, 1, n);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  for (int i = 1; i <= q; i++) {
    int v, l, k;
    cin >> v >> l >> k;
    req[v].push_back({i, {l, k}});
  }
  dfs(1, 1);
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
