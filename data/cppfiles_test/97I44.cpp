#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, q, par[200005];
int dp[200005][255];
vector<int> muchii[200005];
void dfs(int nod) {
  for (auto i : muchii[nod])
    if (i != par[nod]) {
      par[i] = nod;
      dfs(i);
    }
}
void solve(long long v, long long k) {
  dp[v][k] = 0;
  for (auto i : muchii[v])
    if (i != par[v]) {
      solve(i, k);
    }
  for (auto i : muchii[v])
    if (i != par[v]) {
      long long val = max(dp[i][k] - k, 1LL);
      dp[v][k] += val;
    }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    muchii[a].push_back(b);
    muchii[b].push_back(a);
  }
  dfs(1);
  for (int k = 0; k <= 100; k++) solve(1, k);
  cin >> q;
  while (q--) {
    long long v, k;
    cin >> v >> k;
    if (k <= 100)
      cout << dp[v][k] << '\n';
    else if (k <= 150 && dp[1][k] == 0) {
      solve(1, k);
      cout << dp[v][k] << '\n';
    } else
      cout << (int)muchii[v].size() - (v != 1) << '\n';
  }
  return 0;
}
