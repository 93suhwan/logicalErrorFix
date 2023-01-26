#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int iinf = (int)1e9 + 10;
const long long linf = (long long)1e18 + 10;
const int maxn = 3e5 + 10;
int p[maxn], rnk[maxn];
vector<int> gr[maxn];
int get(int v) {
  if (p[v] == v) return v;
  return p[v] = get(p[v]);
}
int unite(int a, int b) {
  a = p[a], b = p[b];
  if (a == b) return 0;
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    p[b] = a;
    if (rnk[a] == rnk[b]) ++rnk[a];
  }
  return 1;
}
int n, m;
void get_path(vector<int>& ans, int u, int v) {
  vector<int> used(n, 0);
  vector<int> pr(n, -1);
  queue<int> q;
  q.push(v);
  used[v] = 1;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int l : gr[k]) {
      if (!used[l]) {
        used[l] = 1;
        pr[l] = k;
        q.push(l);
      }
    }
  }
  int cur = u;
  while (cur != -1) {
    ans.push_back(cur);
    cur = pr[cur];
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (unite(u, v)) {
      gr[u].push_back(v);
      gr[v].push_back(u);
    }
  }
  int q;
  cin >> q;
  vector<int> cnt(n, 0);
  vector<vector<int>> paths(q);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cnt[u]++;
    cnt[v]++;
    get_path(paths[i], u, v);
  }
  int bad = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2 != 0) bad++;
  }
  if (bad > 0) {
    cout << "NO\n";
    cout << bad / 2 << "\n";
  } else {
    cout << "YES\n";
    for (auto& path : paths) {
      cout << path.size() << "\n";
      for (int x : path) cout << x + 1 << " ";
      cout << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
