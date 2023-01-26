#include <bits/stdc++.h>
using namespace std;
template <class T>
void smin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void smax(T &a, T b) {
  a = max(a, b);
}
void yes() { cout << "Yes" << endl; }
void no() { cout << "No" << endl; }
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
const long long MOD = 1e9 + 7;
vector<int> merge(vector<vector<int>> &dists) {
  vector<int> out;
  for (int i = 0; i < dists.size(); i++) {
    for (int j = 0; j < dists[i].size(); j++) {
      out.push_back(dists[i][j]);
    }
  }
  return out;
}
vector<vector<int>> get_children_lenghts(int head, vector<bool> &vis,
                                         vector<vector<int>> &G) {
  vector<vector<int>> out;
  if (vis[head]) return out;
  vis[head] = true;
  for (auto el : G[head]) {
    if (vis[el]) continue;
    vector<int> row;
    row.push_back(1);
    vector<vector<int>> dists = get_children_lenghts(el, vis, G);
    vector<int> lenghts = merge(dists);
    for (auto el : lenghts) row.push_back(el + 1);
    out.push_back(row);
  }
  return out;
}
vector<int> transform(vector<int> &lenghts, int n) {
  vector<int> out(n + 1);
  for (auto el : lenghts) {
    out[el] += 1;
  }
  return out;
}
long long combs(vector<int> &nums, int k) {
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, 0));
  dp[0][1] = nums[0] % MOD;
  for (int i = 1; i < n; i++) dp[i][1] = (nums[i] + dp[i - 1][1]) % MOD;
  for (int k_idx = 2; k_idx <= k; k_idx++) {
    for (int i = k_idx - 1; i < n; i++) {
      dp[i][k_idx] = (dp[i - 1][k_idx] + nums[i] * dp[i - 1][k_idx - 1]) % MOD;
    }
  }
  return dp[n - 1][k];
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> G(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long out = 0;
  if (k == 2) {
    cout << (n * (n - 1)) / 2 << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    vector<bool> vis(n + 1, false);
    vector<vector<int>> ls = get_children_lenghts(i, vis, G);
    vector<vector<int>> lenghts;
    for (auto &el : ls) {
      lenghts.push_back(transform(el, n));
    }
    vector<vector<int>> poss;
    for (int i = 1; i <= n; i++) {
      vector<int> nums;
      for (auto &el : lenghts) {
        if (el[i] != 0) nums.push_back(el[i]);
      }
      if (nums.size() >= k) {
        poss.push_back(nums);
      }
    }
    for (auto &nums : poss) {
      out = (out + combs(nums, k)) % MOD;
    }
  }
  cout << out << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
