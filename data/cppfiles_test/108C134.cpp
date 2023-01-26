#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4 * 1e5 + 7;
const int INF = 1e10 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
int n, a[MAX_N], b[MAX_N], cnt, constant[MAX_N];
vector<pair<int, pair<int, int>>> in;
vector<int> adj[MAX_N], radj[MAX_N], num_cnt[MAX_N], tp;
bool seen[MAX_N], mark[MAX_N];
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) in.push_back({a[i], {b[i], i}});
  sort(in.begin(), in.end());
  for (int i = 0; i < n - 1; i++) {
    int v = in[i + 1].second.second;
    int u = in[i].second.second;
    adj[v].push_back(u);
    radj[u].push_back(v);
  }
  in.clear();
  for (int i = 0; i < n; i++) in.push_back({b[i], {a[i], i}});
  sort(in.begin(), in.end());
  for (int i = 0; i < n - 1; i++) {
    int v = in[i + 1].second.second;
    int u = in[i].second.second;
    adj[v].push_back(u);
    radj[u].push_back(v);
  }
}
void dfs(int root) {
  seen[root] = true;
  for (int x : adj[root])
    if (!seen[x]) dfs(x);
  tp.push_back(root);
}
void sfd(int root, int cnt) {
  seen[root] = true;
  for (int x : radj[root])
    if (!seen[x]) sfd(x, cnt);
  num_cnt[cnt].push_back(root);
  constant[root] = cnt;
}
void scc() {
  for (int i = 0; i < n; i++)
    if (!seen[i]) dfs(i);
  fill(seen, seen + n + 2, 0);
  for (int i = n - 1; i >= 0; i--) {
    if (!seen[tp[i]]) sfd(tp[i], cnt++);
  }
  return;
}
void solve() {
  if (cnt == 1) {
    for (int i = 0; i < n; i++) cout << 1;
    cout << '\n';
    return;
  }
  vector<int> ans;
  for (int i = 0; i < cnt; i++) {
    bool bol = true;
    for (int x : num_cnt[i]) {
      for (int y : radj[x])
        if (constant[y] != i) bol = false;
    }
    if (bol) ans.push_back(i);
  }
  if (ans.size() > 1) {
    for (int i = 0; i < n; i++) cout << 0;
    cout << '\n';
    return;
  }
  for (int x : num_cnt[ans[0]]) mark[x] = 1;
  for (int i = 0; i < n; i++) {
    if (mark[i])
      cout << 1;
    else
      cout << 0;
  }
  cout << '\n';
  return;
}
void Clear() {
  for (int i = 0; i < n; i++) {
    constant[i] = 0;
    adj[i].clear();
    radj[i].clear();
    num_cnt[i].clear();
    seen[i] = 0;
    mark[i] = 0;
  }
  cnt = 0;
  in.clear();
  tp.clear();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    init();
    scc();
    solve();
    Clear();
  }
}
