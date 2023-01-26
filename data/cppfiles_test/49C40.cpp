#include <bits/stdc++.h>
using namespace std;
struct query {
  int v, l, k;
  int idx;
};
const int MAX = 1e6;
vector<int> a;
vector<vector<int>> adj;
vector<vector<query>> queries;
vector<int> ans;
vector<int> cnt;
vector<int> p;
vector<int> inv;
vector<int> lowerbnd;
int n;
bool debg = false;
void DFS(int v, int par) {
  {
    int pos = lowerbnd[cnt[a[v]] + 1] - 1;
    if (debg) cout << "pos = " << pos << '\n';
    int val = p[pos];
    swap(p[inv[a[v]]], p[pos]);
    swap(inv[a[v]], inv[val]);
    lowerbnd[cnt[a[v]] + 1]--;
    cnt[a[v]]++;
    if (debg) {
      cout << "p[]: ";
      for (int z = 1; z <= n; z++) cout << p[z] << ' ';
      cout << '\n';
      cout << "lowerbnd[]: ";
      for (int z = 0; z <= n; z++) cout << lowerbnd[z] << ' ';
      cout << '\n';
    }
  }
  for (query Q : queries[v]) {
    if (lowerbnd[Q.l] + Q.k - 1 <= n) {
      ans[Q.idx] = p[lowerbnd[Q.l] + Q.k - 1];
    } else
      ans[Q.idx] = -1;
  }
  for (auto u : adj[v])
    if (u != par) DFS(u, v);
  {
    int pos = lowerbnd[cnt[a[v]]];
    int val = p[pos];
    swap(p[inv[a[v]]], p[pos]);
    swap(inv[a[v]], inv[val]);
    lowerbnd[cnt[a[v]]]++;
    cnt[a[v]]--;
  }
}
void solve() {
  int q;
  cin >> n >> q;
  vector<int> all_q;
  a.resize(n + 1);
  adj.resize(n + 1);
  queries.resize(n + 1);
  ans.resize(q + 1);
  cnt.resize(n + 1);
  p.resize(n + 1);
  inv.resize(n + 1);
  lowerbnd.resize(n + 1);
  for (int j = 1; j <= n; j++) cin >> a[j];
  for (int z = 0; z < n - 1; z++) {
    int p;
    cin >> p;
    adj[z + 2].push_back(p);
    adj[p].push_back(z + 2);
  }
  for (int j = 0; j < q; j++) {
    query Q;
    Q.idx = j;
    cin >> Q.v >> Q.l >> Q.k;
    queries[Q.v].push_back(Q);
  }
  lowerbnd[0] = 1;
  for (int j = 1; j <= n; j++) {
    p[j] = j;
    inv[j] = j;
    lowerbnd[j] = n + 1;
  }
  DFS(1, 0);
  for (int j = 0; j < q; j++) cout << ans[j] << ' ';
  cout << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    adj.clear();
    queries.clear();
    ans.clear();
    cnt.clear();
    p.clear();
    inv.clear();
    lowerbnd.clear();
    solve();
  }
  return 0;
}
