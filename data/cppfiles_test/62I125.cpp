#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long mod = (long long)1e9 + 7;
vector<vector<int>> adj;
vector<int> ans;
int a = 0;
map<int, int> vs;
bool valid = false;
void dfs(int n) {
  vs[n]++;
  ans.push_back(n);
  for (auto i : adj[n]) {
    if (ans.size() == a + 1) {
      for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
      cout << '\n';
      valid = true;
      return;
    }
    if (!vs[i]) {
      dfs(i);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  a = n;
  adj.resize(2 * n + 1);
  for (int i = 1; i < n; i++) adj[i].push_back(i + 1);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0)
      adj[i + 1].push_back(n + 1);
    else
      adj[n + 1].push_back(i + 1);
  }
  for (int i = 1; i <= n + 1; i++) {
    if (valid) break;
    ans.empty();
    dfs(i);
  }
  if (!valid) cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
