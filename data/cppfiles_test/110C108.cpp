#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, M = 1e9 + 7, OO = 0x3f3f3f3f;
long long t, n, x;
vector<long long> adj[N];
long long k[N];
long long BFS() {
  priority_queue<pair<long long, long long>> pq;
  vector<pair<long long, long long>> fans;
  long long vs = 0;
  for (int i = 0; i < n; ++i) {
    if (k[i] == 0) pq.push({0, -i});
  }
  long long ret = 0;
  while (!pq.empty()) {
    pair<long long, long long> p = pq.top();
    long long u = -p.second;
    long long pr = -p.first;
    ret = max(ret, pr);
    fans.push_back({u, pr});
    pq.pop();
    for (auto v : adj[u]) {
      k[v]--;
      if (k[v] == 0) {
        if (v > u)
          pq.push({-pr, -v});
        else
          pq.push({-(pr + 1), -v});
      }
    }
  }
  if (fans.size() == n)
    return ret + 1;
  else
    return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> k[i];
      for (int j = 0; j < k[i]; ++j) {
        cin >> x;
        x--;
        adj[x].push_back(i);
      }
    }
    long long ans = BFS();
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) adj[i].clear();
  }
  return 0;
}
