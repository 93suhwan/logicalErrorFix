#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long n;
  cin >> n;
  vector<long long> adj[n];
  vector<long long> indegree(n);
  for (long long v = 0; v < n; v++) {
    long long u, k;
    cin >> k;
    while (k--) {
      cin >> u;
      u--;
      adj[u].push_back(v);
      indegree[v]++;
    }
  }
  set<long long> s;
  for (long long i = 0; i < n; i++)
    if (indegree[i] == 0) s.insert(i);
  long long res = 0, cnt = 0;
  while (!s.empty()) {
    res++;
    long long curr = -1;
    while (true) {
      auto it = s.upper_bound(curr);
      if (it == s.end()) break;
      curr = *it;
      cnt++;
      s.erase(it);
      for (long long &v : adj[curr]) {
        indegree[v]--;
        if (indegree[v] == 0) s.insert(v);
      }
    }
  }
  cout << (cnt == n ? res : -1) << "\n";
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
