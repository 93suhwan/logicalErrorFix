#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n, q;
vector<int> sg, a, ans, cnt;
vector<vector<int>> g, pos;
vector<vector<pair<int, pair<int, int>>>> Q;
vector<pair<int, int>> b;
int R = 1;
void add(int v, int d) {
  v += R;
  while (v > 0) {
    sg[v] += d;
    v >>= 1;
  }
}
int get_sum(int x, int xl, int xr, int ql, int qr) {
  if (qr <= xl || xr <= ql) return 0;
  if (ql <= xl && xr <= qr) return sg[x];
  int mid = (xl + xr) >> 1;
  return get_sum(x * 2, xl, mid, ql, qr) + get_sum(x * 2 + 1, mid, xr, ql, qr);
}
int get_ans(int x, int xl, int xr, int k) {
  if (xl + 1 == xr) return x - R;
  int mid = (xl + xr) >> 1;
  if (sg[x * 2] >= k) return get_ans(x * 2, xl, mid, k);
  return get_ans(x * 2 + 1, mid, xr, k - sg[x * 2]);
}
void dfs(int v) {
  add(pos[a[v]][cnt[a[v]]], -1);
  cnt[a[v]]++;
  add(pos[a[v]][cnt[a[v]]], 1);
  for (auto [i, QQ] : Q[v]) {
    auto [l, k] = QQ;
    int tl = -1;
    int tr = (int)b.size();
    while (tl + 1 < tr) {
      int mid = (tl + tr) >> 1;
      if (b[mid].first >= l)
        tr = mid;
      else
        tl = mid;
    }
    k += get_sum(1, 0, R, 0, tr);
    int s = get_sum(1, 0, R, 0, R);
    if (s < k) {
      ans[i] = -1;
    } else {
      int B = get_ans(1, 0, R, k);
      ans[i] = b[B].second + 1;
    }
  }
  for (auto w : g[v]) dfs(w);
  add(pos[a[v]][cnt[a[v]]], -1);
  cnt[a[v]]--;
  add(pos[a[v]][cnt[a[v]]], 1);
}
void solve() {
  cin >> n >> q;
  a.assign(n, 0);
  ans.assign(q, -1);
  cnt.assign(n, 0);
  pos.assign(n, vector<int>());
  g.assign(n, vector<int>());
  Q.assign(n, vector<pair<int, pair<int, int>>>());
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  for (int i = 0; i < q; ++i) {
    int v, l, k;
    cin >> v >> l >> k;
    --v;
    Q[v].push_back({i, {l, k}});
  }
  b.clear();
  for (int i = 0; i < n; ++i) {
    if (cnt[a[i]] == 0) b.emplace_back(cnt[a[i]], a[i]);
    cnt[a[i]]++;
    b.emplace_back(cnt[a[i]], a[i]);
  }
  R = 1;
  while (R <= (int)b.size()) R *= 2;
  sg.assign(2 * R, 0);
  sort(b.begin(), b.end());
  for (int i = 0; i < (int)b.size(); ++i) pos[b[i].second].push_back(i);
  cnt.assign(n, 0);
  for (int i = 0; i < (int)b.size() && b[i].first == 0; ++i) add(i, 1);
  dfs(0);
  for (int i = 0; i < q; ++i) cout << ans[i] << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
