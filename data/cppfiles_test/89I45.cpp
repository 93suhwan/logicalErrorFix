#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 4;
vector<vector<int>> graph(maxn);
vector<int> parent(maxn, -1);
void dfs(int n, int p) {
  for (int it : graph[n]) {
    if (it == p) continue;
    parent[it] = n;
    dfs(it, n);
  }
  return;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    graph[i].clear();
    parent[i] = -1;
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  parent[0] = 0;
  vector<bool> sign(n, 0);
  vector<int> reduction(n, 0);
  queue<int> q;
  vector<bool> visited(n, 0);
  for (int i = 1; i < n; i++) {
    if (int(graph[i].size()) == 1) {
      q.push(i);
      visited[i] = 1;
    }
  }
  dfs(0, -1);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    int p = parent[node];
    if (sign[node] == 1) {
      reduction[p] += 1 + reduction[node];
      sign[p] = sign[p] | 0;
    } else {
      sign[p] = sign[p] | 1;
      reduction[p] += reduction[node];
    }
    if (visited[p] == 0) {
      q.push(p);
      visited[p] = 1;
    }
  }
  bool check = 0;
  int total_reduce = 0;
  for (int it : graph[0]) {
    int reduce = 0;
    if (sign[it] == 0) {
      reduce += reduction[it];
      check = 1;
    } else {
      reduce += reduction[it] + 1;
    }
    total_reduce += max(0, reduce);
  }
  int buds = total_reduce;
  int leaves = n - 2 * buds;
  if (check == 1) {
    leaves--;
  }
  cout << leaves << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
