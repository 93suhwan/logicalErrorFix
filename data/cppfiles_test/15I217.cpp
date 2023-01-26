#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int ans;
vector<vector<int> > g;
vector<int> cnt;
int mul(int a, int b) { return ((a * 1LL * b) % mod); }
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void calculate(int t, int k) {
  vector<vector<int> > dp(t + 1, vector<int>(k + 1));
  dp[0][0] = 1;
  for (int tree_no = 1; tree_no <= t; tree_no++) {
    dp[tree_no][0] = 1;
    for (int sel = 1; sel <= k; sel++) {
      add(dp[tree_no][sel], dp[tree_no - 1][sel]);
      add(dp[tree_no][sel], mul(dp[tree_no - 1][sel - 1], cnt[tree_no]));
    }
  }
  add(ans, dp[t][k]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    g.clear();
    g.resize(n);
    ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[--u].push_back(--v);
      g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
      int t = g[i].size();
      vector<int> visited(n);
      cnt.resize(t + 1);
      vector<pair<int, int> > layer;
      visited[i] = 1;
      for (int j = 0; j < t; j++) {
        layer.push_back(make_pair(g[i][j], j + 1));
        cnt[j + 1] = 1;
        visited[g[i][j]] = 1;
      }
      while (!layer.empty()) {
        calculate(t, k);
        vector<pair<int, int> > new_layer;
        while (!layer.empty()) {
          int v = (layer.back()).first;
          int tree_no = (layer.back()).second;
          layer.pop_back();
          cnt[tree_no]--;
          for (int child : g[v]) {
            if (!visited[child]) {
              visited[child] = 1;
              new_layer.push_back(make_pair(child, tree_no));
              cnt[tree_no]++;
            }
          }
        }
        layer = new_layer;
      }
    }
    if (k == 2) add(ans, n - 1);
    cout << ans << '\n';
  }
}
