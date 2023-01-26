#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long int n, m;
vector<long long int> adj[1];
bool visited[1];
long long int start[1];
long long int end[1];
long long int parent[1];
long long int level[1];
vector<long long int> dfs_order;
void dfs(long long int node) {
  visited[node] = true;
  for (long long int next : adj[node]) {
    if (!visited[next]) {
      parent[next] = node;
      level[next] = level[node] + 1;
      dfs(next);
    }
  }
}
long long int dist[1];
void bfs(long long int start) {
  memset(dist, -1, sizeof dist);
  queue<long long int> q;
  dist[start] = 0;
  q.push(start);
  while (!q.empty()) {
    long long int v = q.front();
    q.pop();
    for (long long int e : adj[v]) {
      if (dist[e] == -1) {
        dist[e] = dist[v] + 1;
        q.push(e);
      }
    }
  }
}
long long int lift(long long int a, long long int dist,
                   vector<vector<long long int>> &up) {
  for (long long int i = 0; i < 20; i++) {
    if (dist & (1 << i)) {
      a = up[a][i];
    }
  }
  return a;
}
void preprocesslift(vector<vector<long long int>> &up) {
  for (long long int j = 1; j < 20; j++) {
    for (long long int i = 1; i <= n; i++) {
      if (up[i][j - 1] != -1) {
        up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t > 0) {
    long long int x;
    cin >> n;
    multiset<long long int> s;
    long long int mn = numeric_limits<long long int>::max();
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      mn = min(mn, x);
      s.insert(x);
    }
    long long int temp = 0;
    while (s.size() > 1) {
      long long int x = *s.begin() + temp;
      mn = max(mn, *s.begin() + temp);
      temp += -x;
      s.erase(s.begin());
    }
    mn = max(mn, *s.begin() + temp);
    cout << mn << "\n";
    t--;
  }
  return 0;
}
