#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 4000;
int a[1 + MAX_N];
vector<int> gr[1 + MAX_N];
int create_tree(int lb, int rb) {
  if (lb == rb) return lb;
  int id = lb;
  for (int i = lb + 1; i <= rb; i++)
    if (a[id] > a[i]) id = i;
  if (lb < id) gr[id].push_back(create_tree(lb, id - 1));
  if (rb > id) gr[id].push_back(create_tree(id + 1, rb));
  return id;
}
const ll INF = 1e18;
ll dp[1 + MAX_N][1 + MAX_N];
int sz[1 + MAX_N];
void upd(ll &a, ll b) {
  if (a < b) a = b;
}
int m;
void calc_dp(int node) {
  dp[node][0] = 0;
  dp[node][1] = 1ll * (m - 1) * a[node];
  sz[node] = 1;
  for (int son : gr[node]) {
    calc_dp(son);
    for (int sz_node = sz[node]; sz_node >= 0; sz_node--)
      for (int sz_son = sz[son]; sz_son >= 0; sz_son--)
        upd(dp[node][sz_node + sz_son], dp[node][sz_node] + dp[son][sz_son] -
                                            2ll * sz_son * sz_node * a[node]);
    sz[node] += sz[son];
    if (sz[node] > m) sz[node] = m;
  }
}
void solve_test() {
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int root = create_tree(1, n);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = -INF;
  calc_dp(root);
  cout << dp[root][m] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve_test();
  return 0;
}
