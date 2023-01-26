#include <bits/stdc++.h>
using namespace std;
int mul(int x, int y) { return (long long)x * y % 1000000007; }
int add(int x, int y) {
  x += y;
  while (x >= 1000000007) x -= 1000000007;
  while (x < 0) x += 1000000007;
  return x;
}
void dfs(int node, int dad, int d, int i, vector<vector<int>>& freq,
         vector<vector<int>>& v) {
  if (freq[i].size() == d) {
    freq[i].push_back(0);
  }
  freq[i][d]++;
  for (int go : v[node]) {
    if (go != dad) {
      dfs(go, node, d + 1, i, freq, v);
    }
  }
}
int calc(int node, vector<vector<int>>& v, int k) {
  int n = v.size() >> 1;
  vector<vector<int>> freq(n);
  for (int i = 0; i < v[node].size(); i++) {
    freq[i].push_back(0);
    dfs(v[node][i], node, 1, i, freq, v);
  }
  int res = 0;
  for (int d = 1 + (node < n); d < n * 2; d += 2) {
    vector<vector<int>> dp(v[node].size() + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int id = 1; id <= v[node].size(); id++) {
      int i = id - 1;
      for (int c = 0; c <= k; c++) {
        int val = 0;
        if (freq[i].size() > d) {
          val = freq[i][d];
        }
        dp[id][c] = add(dp[id - 1][c], mul(c > 0 ? dp[id - 1][c - 1] : 0, val));
      }
    }
    res = add(res, dp[v[node].size()][k]);
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n << 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    v[x].push_back(n + i);
    v[n + i].push_back(x);
    v[n + i].push_back(y);
    v[y].push_back(n + i);
  }
  if (k == 1) {
    cout << n << "\n";
    return;
  }
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    ans = add(ans, calc(i, v, k));
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
