#include <bits/stdc++.h>
using namespace std;
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
vector<int> calculate_small_dp(const vector<vector<int>>& children,
                               const vector<int>& order, int k) {
  int n = children.size();
  vector<int> dp(n, 0);
  for (int i : order) {
    for (int ch : children[i]) {
      dp[i] += max(dp[ch] - k, 1);
    }
  }
  return dp;
}
int& chmax(int& x, int y) {
  if (y > x) x = y;
  return x;
}
vector<int> solve(const vector<vector<int>>& adj, const vector<int>& v,
                  const vector<int>& k) {
  const int THRESH1 = 500;
  const int THRESH2 = 400;
  int n = adj.size();
  vector<int> parents = get_parents(adj, 0);
  vector<vector<int>> children = get_children(parents);
  vector<int> order = get_order(children, 0);
  int q = v.size();
  vector<int> ans(q);
  vector<vector<int>> by_k(THRESH1);
  for (int qi = 0; qi < q; ++qi) {
    if (k[qi] < THRESH1) {
      by_k[k[qi]].push_back(qi);
    }
  }
  for (int ki = 0; ki < THRESH1; ++ki) {
    if (by_k[ki].empty()) continue;
    vector<int> dp = calculate_small_dp(children, order, ki);
    for (int qi : by_k[ki]) {
      ans[qi] = dp[v[qi]];
    }
  }
  vector<vector<int>> dp(n);
  for (int i : order) {
    dp[i].resize(1, 0);
    for (int ch : children[i]) {
      int m = min(int(dp[i].size()) + int(dp[ch].size()), THRESH2 + 1);
      vector<int> u(m, 0);
      for (int j = 0; j < int(dp[i].size()); ++j) {
        u[j] = dp[i][j] + 1;
      }
      for (int j1 = 0; j1 < int(dp[i].size()); ++j1) {
        for (int j2 = 0; (j2 < int(dp[ch].size())) && ((j1 + j2 + 1) < m);
             ++j2) {
          chmax(u[j1 + 1 + j2], dp[i][j1] + dp[ch][j2]);
        }
      }
      u.swap(dp[i]);
    }
  }
  for (int qi = 0; qi < q; ++qi) {
    if (k[qi] >= THRESH1) {
      for (int i = 0; i < int(dp[v[qi]].size()); ++i) {
        chmax(ans[qi], dp[v[qi]][i] - i * k[qi]);
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int q;
  cin >> q;
  vector<int> v(q), k(q);
  for (int i = 0; i < q; ++i) {
    cin >> v[i] >> k[i];
    --v[i];
  }
  vector<int> ans = solve(adj, v, k);
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}
