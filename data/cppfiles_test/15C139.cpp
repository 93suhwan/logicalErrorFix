#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e2 + 5;
int add(int a, int b) {
  int res = a + b;
  if (res >= MOD) res -= MOD;
  return res;
}
int mult(int a, int b) {
  long long res = 1LL * a * b;
  if (res >= MOD) res %= MOD;
  return res;
}
int ans;
vector<vector<int>> g;
int dfs(int node, int p, int dist) {
  if (dist == 0) return 1;
  int res = 0;
  for (auto to : g[node]) {
    if (to != p) res += dfs(to, node, dist - 1);
  }
  return res;
}
vector<int> delta;
vector<vector<int>> dp;
int max_n;
int solve(int p, int left) {
  if (left == 0) return 1;
  if (p >= max_n) return 0;
  int &res = dp[p][left];
  if (~res) return res;
  res = 0;
  res = add(res, solve(p + 1, left));
  res = add(res, mult(delta[p], solve(p + 1, left - 1)));
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    ans = 0;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int st, et;
      cin >> st >> et;
      --st;
      --et;
      g[st].emplace_back(et);
      g[et].emplace_back(st);
    }
    if (k == 2) {
      for (int i = n - 1; i >= 1; i--) {
        ans = add(ans, i);
      }
    } else {
      for (int distance = 1; distance <= n; distance++) {
        for (int i = 0; i < n; i++) {
          delta.clear();
          for (auto to : g[i]) delta.emplace_back(dfs(to, i, distance - 1));
          max_n = (int)delta.size();
          if (max_n < k) continue;
          dp = vector<vector<int>>(max_n, vector<int>(k + 1, -1));
          ans = add(ans, solve(0, k));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
