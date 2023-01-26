#include <bits/stdc++.h>
using namespace std;
const int nax = (int)1e6 + 10;
const int INF = (int)1e9 + 47;
int a[nax];
vector<int> g[nax];
vector<pair<pair<int, int>, int>> query[nax];
set<int> hv[nax];
int cnt[nax];
int fenwick[nax];
int ans[nax];
void update(int pos, int val) {
  while (pos <= nax - 5) {
    fenwick[pos] += val;
    pos += (pos) & (-pos);
  }
}
int ask(int pos) {
  int sum = 0;
  while (pos > 0) {
    sum += fenwick[pos];
    pos -= pos & (-pos);
  }
  return sum;
}
int timer = 0;
void dfs(int v) {
  if (timer++ > 10) return;
  cnt[a[v]]++;
  hv[cnt[a[v]]].insert(a[v]);
  if (cnt[a[v]] != 0) hv[cnt[a[v]] - 1].erase(a[v]);
  update(cnt[a[v]] + 1, 1);
  if (cnt[a[v]] != 1) update(cnt[a[v]], -1);
  for (auto x : query[v]) {
    int l = 0, r = (int)1e6 + 2;
    for (int it = 0; it < 22; it++) {
      int mid = (l + r) / 2;
      if (ask(mid + 1) - ask(x.first.second) < x.first.first)
        l = mid;
      else
        r = mid;
    }
    if (ask(l + 2) - ask(x.first.second) < x.first.first) {
      ans[x.second] = -1;
    } else
      ans[x.second] = *hv[l + 1].begin();
  }
  for (auto to : g[v]) {
    dfs(to);
  }
  cnt[a[v]]--;
  update(cnt[a[v]] + 2, -1);
  if (cnt[a[v]] != 0) update(cnt[a[v]] + 1, 1);
  hv[cnt[a[v]] + 1].erase(a[v]);
  if (cnt[a[v]] != 0) hv[cnt[a[v]]].insert(a[v]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
    int id = 0;
    while (q--) {
      int v, l, k;
      cin >> v >> l >> k;
      --v;
      query[v].push_back({{k, l}, id++});
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      query[i].clear();
      g[i].clear();
    }
  }
}
