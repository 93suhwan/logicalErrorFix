#include <bits/stdc++.h>
using namespace std;
void fileio() {}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<vector<long long int>> adj;
vector<long long int> isbud;
vector<long long int> isleaf;
void dfs1(long long int a, long long int p) {
  isleaf[a] = 1;
  bool buddy = true;
  for (auto to : adj[a]) {
    if (to == p) continue;
    dfs1(to, a);
    isleaf[a] = 0;
  }
  long long int leaf = 0;
  for (auto to : adj[a]) {
    if (to == p) continue;
    if (isleaf[to]) {
      leaf++;
    }
    if (isleaf[to] || isbud[to] != -1) {
      continue;
    }
    buddy = false;
  }
  bool allbud = true;
  for (auto to : adj[a]) {
    if (to == p) continue;
    if (isbud[to] == -1) {
      allbud = false;
    }
  }
  if (allbud) {
    isleaf[a] = 1;
  }
  if (isleaf[a] == 0 && buddy) {
    isbud[a] = leaf;
  }
}
void solve() {
  long long int n;
  cin >> n;
  adj.assign(n, vector<long long int>());
  isbud.assign(n, -1);
  isleaf.assign(n, 0);
  for (long long int i = 1; i <= n - 1; i++) {
    long long int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  dfs1(0, -1);
  long long int leafs = 0, buds = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    if (isleaf[i] == 1) {
      leafs++;
    }
    if (isbud[i] != -1) {
      buds++;
    }
  }
  long long int ans = leafs - buds;
  if (isbud[0] != -1) {
    ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  fileio();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int yy = 1; yy <= t; yy++) {
    solve();
  }
  return 0;
}
