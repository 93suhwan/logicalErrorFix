#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> adj;
vector<long long> indegree;
vector<long long> topo;
long long n;
void topological() {
  queue<long long> q;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (long long i = 1; i <= n; i++)
    if (indegree[i] == 0) q.push(i);
  while (!q.empty()) {
    long long sz = q.size();
    while (sz--) {
      long long u = q.front();
      q.pop();
      topo.push_back(u);
      for (long long &v : adj[u]) {
        indegree[v]--;
        if (indegree[v] == 0) pq.push(v);
      }
    }
    while (!pq.empty()) {
      q.push(pq.top());
      pq.pop();
    }
  }
}
void test_case() {
  cin >> n;
  topo.clear();
  adj = vector<vector<long long>>(n + 1);
  indegree = vector<long long>(n + 1);
  long long k;
  for (long long v = 1; v <= n; v++) {
    cin >> k;
    long long u;
    while (k--) {
      cin >> u;
      adj[u].push_back(v);
      indegree[v]++;
    }
  }
  topological();
  if ((long long)topo.size() != n) {
    cout << "-1"
         << "\n";
    return;
  }
  reverse(topo.begin(), topo.end());
  vector<long long> lis;
  for (long long &x : topo) {
    if (lis.empty() or x > lis.back()) {
      lis.push_back(x);
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), x);
      *it = x;
    }
  }
  cout << (long long)lis.size() << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
