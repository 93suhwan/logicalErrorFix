#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &g, vector<int> &vis, stack<int> &st, int u,
         int &flag) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (vis[v] == 0) {
      dfs(g, vis, st, v, flag);
    } else if (vis[v] == 1) {
      flag = 1;
    }
  }
  st.push(u);
  vis[u] = 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int flag = 0;
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<vector<int>> list(n);
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int temp;
        cin >> temp;
        list[i].push_back(temp - 1);
        g[temp - 1].push_back(i);
      }
    }
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) dfs(g, vis, st, i, flag);
    }
    if (flag == 1) {
      cout << -1 << endl;
      continue;
    }
    vector<int> dp(n, 0);
    while (!st.empty()) {
      int top = st.top();
      st.pop();
      dp[top] = 1;
      for (auto node : list[top]) {
        if (node > top)
          dp[top] = max(dp[top], dp[node] + 1);
        else
          dp[top] = max(dp[top], dp[node]);
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}
