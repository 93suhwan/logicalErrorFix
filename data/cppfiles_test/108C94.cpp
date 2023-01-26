#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> &a, long long int s, long long int e) {
  for (long long int i = s; i <= e - 1; i++) {
    cout << a[i] << " ";
  }
  cout << a[e];
}
void dfs(long long int cur, vector<vector<long long int>> &graph,
         vector<bool> &visited) {
  visited[cur] = true;
  for (auto nbr : graph[cur]) {
    if (!visited[nbr]) {
      dfs(nbr, graph, visited);
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int>> graph(n);
  vector<pair<long long int, long long int>> a(n), b(n);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (long long int i = 0; i <= n - 2; i++) {
    graph[a[i].second].push_back(a[i + 1].second);
    graph[b[i].second].push_back((b[i + 1].second));
  }
  vector<bool> visited(n, false);
  dfs(a[n - 1].second, graph, visited);
  for (long long int i = 0; i <= n - 1; i++) {
    cout << visited[i];
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
