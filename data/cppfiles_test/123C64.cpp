#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 5;
int n, k, par[mx], dep[mx], rem[mx], cnt[mx];
long long ans = -1e18;
vector<int> adj[mx], leaves;
void dfs(int cur) {
  for (int nxt : adj[cur])
    if (nxt != par[cur]) {
      par[nxt] = cur;
      dep[nxt] = dep[cur] + 1;
      dfs(nxt);
    }
  if (par[cur] and adj[cur].size() == 1) leaves.push_back(cur);
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  sort(leaves.begin(), leaves.end(),
       [&](int a, int b) { return dep[a] > dep[b]; });
  for (int i : leaves) {
    int cur = i;
    while (cur and !rem[cur]) rem[cur] = 1, cnt[i]++, cur = par[cur];
  }
  sort(leaves.begin(), leaves.end(),
       [&](int a, int b) { return cnt[a] > cnt[b]; });
  int okBlueSpots = n;
  for (int red = 1; red <= k; red++) {
    if (red <= leaves.size()) okBlueSpots -= cnt[leaves[red - 1]];
    int blue = min(okBlueSpots, n / 2);
    ans = max(ans, (long long)(n - red - blue) * (red - blue));
  }
  cout << ans << endl;
}
