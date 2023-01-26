#include <bits/stdc++.h>
constexpr bool test_cases = true;
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(n);
  int p;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    a[i] = {p, i};
  }
  for (int i = 0; i < n; ++i) {
    cin >> p;
    b[i] = {p, i};
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  vector<bool> visited(n, false);
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int next, curr;
    next = a[i + 1].second;
    curr = a[i].second;
    adj[curr].push_back(next);
    next = b[i + 1].second;
    curr = b[i].second;
    adj[curr].push_back(next);
  }
  vector<char> ans(n, '0');
  int pos1 = a[n - 1].second;
  int pos2 = b[n - 1].second;
  queue<int> q;
  q.push(pos1);
  q.push(pos2);
  visited[pos1] = true;
  ans[pos1] = '1';
  visited[pos2] = true;
  ans[pos2] = '1';
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : adj[v]) {
      if (!visited[u]) {
        visited[u] = true;
        ans[u] = '1';
        q.push(u);
      }
    }
  }
  for (auto c : ans) cout << c;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  if (test_cases) cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
