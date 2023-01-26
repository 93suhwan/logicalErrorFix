#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
vector<int> adj[N];
int ind[N];
int dp[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      ind[i] = dp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      for (int j = 1; j <= k; j++) {
        int ai;
        scanf("%d", &ai);
        adj[ai].push_back(i);
        ind[i]++;
      }
    }
    int vis = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (ind[i] == 0) {
        q.push(i);
        vis++;
      }
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto it : adj[node]) {
        ind[it]--;
        if (node < it) {
          dp[it] = max(dp[it], dp[node]);
        } else {
          dp[it] = max(dp[it], dp[node] + 1);
        }
        if (ind[it] == 0) {
          q.push(it);
          vis++;
        }
      }
    }
    if (vis != n) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", *max_element(dp + 1, dp + n + 1) + 1);
  }
  return 0;
}
