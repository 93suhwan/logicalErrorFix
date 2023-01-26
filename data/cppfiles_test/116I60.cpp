#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N = 3e5 + 9, mod = 998244353;
int n, m, k;
int indegree[N], outdegree[N];
vector<int> adj[N];
vector<int> undirected[N];
bool bad[N];
void dfsbads(int node) {
  if (bad[node]) return;
  bad[node] = true;
  for (auto i : undirected[node]) dfsbads(i);
}
int dfsChain(int node) {
  assert(bad[node] == false);
  bad[node] = true;
  if (adj[node].empty()) return 1;
  assert(adj[node].size() == 1);
  return 1 + dfsChain(adj[node][0]);
}
long long freq[N];
long long dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  while (n--) {
    int c, x;
    cin >> c >> x;
    for (int i = 1; i < c; i++) {
      int y;
      cin >> y;
      adj[x].push_back(y);
      undirected[x].push_back(y);
      undirected[y].push_back(x);
      outdegree[x]++;
      indegree[y]++;
      x = y;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (indegree[i] > 1 || outdegree[i] > 1) dfsbads(i);
  }
  for (int i = 1; i <= k; i++) {
    if (bad[i] || indegree[i]) continue;
    freq[dfsChain(i)]++;
  }
  vector<pair<long long, long long> > v;
  for (int i = 1; i <= m; i++) {
    if (freq[i]) {
      v.push_back({i, freq[i]});
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (auto j : v) {
      if (j.first > i) break;
      dp[i] = (dp[i] + 1LL * j.second * dp[i - j.first]) % mod;
    }
  }
  cout << dp[m];
}
