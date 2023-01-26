#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
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
vector<int> get_order(const vector<vector<int>>& children, int root) {
  int N = children.size();
  vector<int> order(N);
  int idx = 0;
  stack<pair<bool, int>> st;
  st.emplace(true, root);
  while (!st.empty()) {
    bool b = st.top().first;
    int node = st.top().second;
    st.pop();
    if (b) {
      st.emplace(false, node);
      for (int ch : children[node]) {
        st.emplace(true, ch);
      }
    } else {
      order[idx++] = node;
    }
  }
  assert(idx == N);
  return order;
}
vector<int> solve(const vector<pair<int, int>>& edges) {
  int n = edges.size() + 1;
  vector<vector<int>> adj(n);
  for (const pair<int, int>& edge : edges) {
    adj[edge.first].push_back(edge.second);
    adj[edge.second].push_back(edge.first);
  }
  vector<int> parents = get_parents(adj, 0);
  vector<vector<int>> children = get_children(parents);
  vector<int> order = get_order(children, 0);
  vector<int> ans(n, 0);
  ans[0] = 1;
  for (int i = 1; i < n; ++i) {
    ans[0] *= 2;
    if (ans[0] >= MOD) ans[0] -= MOD;
  }
  auto can = [&](int g) -> bool {
    vector<bool> dp(n);
    for (int i : order) {
      int c = 0;
      for (int child : children[i]) {
        c += dp[child];
      }
      if (parents[i] >= 0) {
        if ((c % g) == 0) {
          dp[i] = true;
        } else if (((c + 1) % g) == 0) {
          dp[i] = false;
        } else {
          return false;
        }
      } else {
        if ((c % g) != 0) return false;
      }
    }
    return true;
  };
  for (int g = 2; g < n; ++g) {
    if (((n - 1) % g) == 0) {
      if (can(g)) {
        ans[g - 1] = 1;
        if (--ans[0] < 0) ans[0] += MOD;
      }
    }
  }
  return ans;
}
void test_case() {
  int n;
  cin >> n;
  vector<pair<int, int>> edges(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> edges[i].first >> edges[i].second;
    --edges[i].first;
    --edges[i].second;
  }
  vector<int> ans = solve(edges);
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
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
