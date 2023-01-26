#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  map<int, int> indegree;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int chapter;
      cin >> chapter;
      chapter--;
      adj[chapter].push_back(i);
      indegree[i]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  int read = 0;
  vector<int> readingTime(n, 1);
  while (!q.empty()) {
    read++;
    int node = q.front();
    q.pop();
    for (auto child : adj[node]) {
      if (child > node) {
        readingTime[child] = max(readingTime[child], readingTime[node]);
      } else {
        readingTime[child] = max(readingTime[child], readingTime[node] + 1);
      }
      indegree[child]--;
      if (indegree[child] == 0) {
        q.push(child);
      }
    }
  }
  if (read != n) {
    cout << -1 << endl;
  } else {
    int ans = 0;
    for (auto x : readingTime) {
      ans = max(ans, x);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
