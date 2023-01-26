#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int modadd(int x, int y) {
  int result = x + y;
  if (result >= MOD) result -= MOD;
  return result;
}
int modmult(int x, int y) { return (x * int64_t(y)) % MOD; }
int modaddto(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int64_t modpow(int64_t b, int64_t e) {
  int64_t ans = 1;
  for (; e; b = b * b % MOD, e /= 2)
    if (e & 1) ans = ans * b % MOD;
  return ans;
}
int modinv(int x) { return modpow(x, MOD - 2); }
vector<int> get_parents(const vector<vector<int>>& adj, int root) {
  int n = adj.size();
  vector<int> parents(n, -1);
  stack<pair<int, int>> st;
  st.emplace(root, -1);
  while (!st.empty()) {
    int node = st.top().first;
    parents[node] = st.top().second;
    st.pop();
    for (int i : adj[node]) {
      if (i != parents[node]) {
        st.emplace(i, node);
      }
    }
  }
  return parents;
}
vector<vector<int>> get_children(const vector<int>& parents) {
  int n = parents.size();
  vector<vector<int>> children(n);
  for (int i = 0; i < n; ++i) {
    if (parents[i] >= 0) {
      children[parents[i]].push_back(i);
    }
  }
  return children;
}
vector<int> get_depth(const vector<vector<int>>& children, int root) {
  int n = children.size();
  vector<int> depth(n);
  vector<int> q(1, root);
  int d = 0;
  while (!q.empty()) {
    vector<int> q2;
    for (int i : q) {
      depth[i] = d;
      for (int j : children[i]) {
        q2.push_back(j);
      }
    }
    q2.swap(q);
    d++;
  }
  return depth;
}
int solve(const vector<int>& u, const vector<int>& v, int k) {
  int n = u.size() + 1;
  if (k == 2) {
    return n * (n - 1) / 2;
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
  }
  int ways = 0;
  for (int root = 0; root < n; ++root) {
    if (int(adj[root].size()) < k) continue;
    vector<int> parents = get_parents(adj, root);
    vector<vector<int>> children = get_children(parents);
    vector<int> depth = get_depth(children, root);
    int max_depth = *max_element(depth.begin(), depth.end());
    int nch = children[root].size();
    vector<vector<int>> depths(nch, vector<int>(max_depth, 0));
    for (int chi = 0; chi < nch; ++chi) {
      stack<int> st;
      st.push(children[root][chi]);
      while (!st.empty()) {
        int node = st.top();
        st.pop();
        depths[chi][depth[node] - 1]++;
        for (int j : children[node]) {
          st.push(j);
        }
      }
    }
    for (int d = 0; d < max_depth; ++d) {
      vector<int> dp(1, 1);
      for (int chi = 0; chi < nch; ++chi) {
        vector<int> dp2(chi + 2, 0);
        dp2[0] = dp[0];
        for (int i = 1; i < chi + 2; ++i) {
          dp2[i] = (i < chi + 1) ? dp[i] : 0;
          modaddto(dp2[i], modmult(dp[i - 1], depths[chi][d]));
        }
        dp2.swap(dp);
      }
      assert(int(dp.size()) > k);
      modaddto(ways, dp[k]);
    }
  }
  return ways;
}
void test_case() {
  int n, k;
  cin >> n >> k;
  vector<int> u(n - 1), v(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u[i] >> v[i];
    --u[i];
    --v[i];
  }
  cout << solve(u, v, k) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}
