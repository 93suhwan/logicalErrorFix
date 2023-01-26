#include <bits/stdc++.h>
const int maxN = 2e5 + 10;
using namespace std;
int t;
int n, m;
int a, b;
string c;
vector<pair<int, int>> edges[maxN];
vector<int> visited;
bool flag;
void dfs(int cur) {
  a += visited[cur];
  b += !visited[cur];
  for (auto [node, tt] : edges[cur]) {
    int needed = tt ^ visited[cur];
    if (~visited[node]) {
      flag &= (visited[node] == needed);
    } else {
      visited[node] = needed;
      dfs(node);
    }
  }
}
int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m;
    flag = true;
    for (int j = 0; j < n; ++j) edges[j].clear();
    for (int j = 0; j < m; ++j) {
      int a, b;
      cin >> a >> b >> c;
      --a;
      --b;
      edges[a].push_back({b, c[0] == 'i'});
      edges[b].push_back({a, c[0] == 'i'});
    }
    visited = vector<int>(n + 1, -1);
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      if (visited[j] == -1) {
        visited[j] = 1;
        a = b = 0;
        dfs(j);
        ans += max(a, b);
      }
    }
    cout << (flag ? ans : -1) << endl;
  }
  return 0;
}
