#include <bits/stdc++.h>
using namespace std;
int n, qq;
const int MAXN = 2e6 + 10;
int head[MAXN], l;
struct ed {
  int to, nxt;
} e[MAXN];
void add(int u, int v) {
  e[++l].to = v;
  e[l].nxt = head[u];
  head[u] = l;
}
int a[MAXN];
int c[MAXN];
int lowbit(int x) { return x & -x; }
void upd(int pos, int num) {
  for (int i = pos; i < MAXN; i += lowbit(i)) {
    c[i] += num;
  }
}
int p;
int ans[MAXN];
int vis[MAXN];
set<int> S[MAXN];
vector<pair<pair<int, int>, int>> V[MAXN];
int query(int pos) {
  int num = 0;
  for (int i = pos; i; i -= lowbit(i)) num += c[i];
  return num;
}
void solve(int u) {
  vis[a[u]]++;
  if (vis[a[u]] != 1) {
    S[vis[a[u]] - 1].erase(a[u]);
    upd(vis[a[u]] - 1, -1);
  }
  upd(vis[a[u]], 1);
  S[vis[a[u]]].insert(a[u]);
  for (int p = 0; p < V[u].size(); p++) {
    int num = query(1000000) - query(V[u][p].first.first - 1);
    if (p <= qq && num < V[u][p].first.second) {
      ans[V[u][p].second] = -1;
      continue;
    }
    int l = V[u][p].first.first;
    int r = 1e6 + 5;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(mid) - query(l - 1) >= V[u][p].first.second)
        r = mid - 1;
      else
        l = mid + 1;
    }
    ans[V[u][p].second] = *(S[l].begin());
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    solve(v);
  }
  upd(vis[a[u]], -1);
  S[vis[a[u]]].erase(a[u]);
  vis[a[u]]--;
  if (vis[a[u]]) upd(vis[a[u]], 1), S[vis[a[u]]].insert(a[u]);
}
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> qq;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      int fa;
      cin >> fa;
      add(fa, i);
    }
    for (int i = 1; i <= qq; i++) {
      int v, l, k;
      cin >> v >> l >> k;
      V[v].push_back(make_pair(make_pair(l, k), i));
    }
    p = 1;
    solve(1);
    for (int i = 1; i <= qq; i++) cout << ans[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) vis[i] = head[i] = 0;
    l = 0;
  }
}
