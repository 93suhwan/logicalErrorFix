#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
struct q {
  int id, l, k;
};
const int maxn = 1e6 + 5;
set<int> cnt[maxn];
int bit[maxn];
int lowbit(int x) { return x & -x; }
int n;
void add(int p, int x) {
  for (int i = p; i <= n; i += lowbit(i)) {
    bit[i] += x;
  }
}
ll sum(int p) {
  ll ret = 0;
  for (int i = p; i > 0; i -= lowbit(i)) ret += bit[i];
  return ret;
}
vector<q> qry[maxn];
int ans[maxn], w[maxn], aux[maxn];
vector<int> g[maxn];
void calc(int u) {
  for (auto &qr : qry[u]) {
    int l = qr.l, r = n, res = -1;
    ll tot = sum(qr.l - 1);
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (sum(mid) - tot >= qr.k)
        res = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    if (res == -1)
      ans[qr.id] = -1;
    else
      ans[qr.id] = *cnt[res].begin();
  }
}
void dfs(int u) {
  if (aux[w[u]]) {
    cnt[aux[w[u]]].erase(w[u]);
    add(aux[w[u]], -1);
  }
  aux[w[u]]++;
  cnt[aux[w[u]]].insert(w[u]);
  add(aux[w[u]], 1);
  calc(u);
  for (auto v : g[u]) {
    dfs(v);
  }
  cnt[aux[w[u]]].erase(w[u]);
  add(aux[w[u]], -1);
  aux[w[u]]--;
  if (aux[w[u]]) {
    cnt[aux[w[u]]].insert(w[u]);
    add(aux[w[u]], 1);
  }
}
void solve() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 1, v, l, k; i <= m; ++i) {
    cin >> v >> l >> k;
    qry[v].push_back({i, l, k});
  }
  dfs(1);
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << " \n"[i == m];
  }
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
    qry[i].clear();
  }
}
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
