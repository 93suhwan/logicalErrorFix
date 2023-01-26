#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], fen[maxn], q[maxn][3], cnt[maxn], ans[maxn], n, m;
vector<int> g[maxn], vc[maxn];
set<int> s[maxn];
void add(int ind, int x) {
  if (!ind) return;
  for (int i = ind; i < maxn; i += i & -i) {
    fen[i] += x;
  }
}
int get(int ind) {
  int res = 0;
  for (int i = ind; i > 0; i -= i & -i) {
    res += fen[i];
  }
  return res;
}
int get(int l, int r) { return get(r) - get(l - 1); }
int find(int x) {
  int res = 0;
  for (int i = 19; i >= 0; i--) {
    if (res + (1 << i) < maxn && fen[res + (1 << i)] < x) {
      res += (1 << i);
      x -= fen[res];
    }
  }
  return res + 1;
}
void dfs(int u) {
  s[cnt[a[u]]].erase(a[u]);
  add(cnt[a[u]], -1);
  cnt[a[u]]++;
  s[cnt[a[u]]].insert(a[u]);
  add(cnt[a[u]], 1);
  for (int i : vc[u]) {
    int k = get(1, q[i][1] - 1) + q[i][2];
    if (get(1, maxn - 1) < k) {
      ans[i] = -1;
    } else {
      int ind = find(k);
      ans[i] = (*s[ind].begin());
    }
  }
  vc[u].clear();
  for (int v : g[u]) {
    dfs(v);
  }
  s[cnt[a[u]]].erase(a[u]);
  add(cnt[a[u]], -1);
  cnt[a[u]]--;
  s[cnt[a[u]]].insert(a[u]);
  add(cnt[a[u]], 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      g[x].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      cin >> q[i][0] >> q[i][1] >> q[i][2];
      vc[q[i][0]].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < m; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) g[i].clear();
  }
  return 0;
}
