#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;
vector<int> g[MAXN];
int in[MAXN];
int dp[MAXN];
bool dfs(int n) {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) q.push(i), dp[i] = 1;
  }
  int cnt = 0;
  while (!q.empty()) {
    int now = q.front();
    in[now]--;
    cnt++;
    q.pop();
    for (auto v : g[now]) {
      in[v]--;
      if (now < v)
        dp[v] = max(dp[v], dp[now]);
      else
        dp[v] = max(dp[v], dp[now] + 1);
      if (!in[v]) q.push(v);
    }
  }
  if (cnt != n) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) in[i] = 0, dp[i] = 0;
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        in[i]++;
      }
    }
    bool flag = dfs(n);
    if (flag) {
      int ans = 0;
      for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
      }
      printf("%d\n", ans);
    } else {
      printf("-1\n");
    }
    for (int i = 1; i <= n; i++) g[i].clear();
  }
}
