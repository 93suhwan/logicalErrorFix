#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 600;
long long int n, m;
long long int A[MAX + 1][MAX + 1] = {0};
bool vis[MAX + 1][MAX + 1] = {0};
long long int out[MAX + 1][MAX + 1] = {0};
long long int cmp[MAX + 1][MAX + 1] = {0};
long long int c = 0;
long long int color[MAX * MAX + 1];
long long int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
long long int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
vector<long long int> adj[MAX * MAX + 1];
bool in(long long int x, long long int y) {
  return ((1 <= x) && (x <= n) && (1 <= y) && (y <= m));
}
bool is(long long int x, long long int y) {
  return ((A[x][y] == 1) && (A[x + 1][y] == 1) && (A[x - 1][y] == 1) &&
          (A[x][y - 1] == 0) && (A[x][y + 1] == 0));
}
void DFS(long long int i, long long int j) {
  vis[i][j] = true;
  cmp[i][j] = c;
  for (long long int z = 0; z < 8; z++) {
    if (in(i + dx[z], j + dy[z])) {
      if (!vis[i + dx[z]][j + dy[z]]) {
        if (A[i + dx[z]][j + dy[z]] == 0) DFS(i + dx[z], j + dy[z]);
      }
    }
  }
}
void bipartite() {
  vector<bool> vis(c + 1, false);
  queue<long long int> q;
  color[1] = 0;
  q.push(1);
  vis[1] = true;
  while (!q.empty()) {
    long long int v = q.front();
    q.pop();
    for (auto u : adj[v]) {
      if (vis[u]) continue;
      color[u] = 1 - color[v];
      q.push(u);
      vis[u] = true;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      char ch;
      cin >> ch;
      if (ch == 'X') A[j][i] = 1;
    }
  }
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      if (vis[j][i]) continue;
      c++;
      DFS(j, i);
    }
  }
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      if (A[j][i]) {
        long long int cnt = 0;
        for (long long int z = 0; z < 4; z++)
          cnt += (A[j + dx[z]][i + dy[z]] == 0);
        if (cnt % 2) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
  for (long long int j = 1; j <= n; ++j) {
    for (long long int i = 1; i <= m; i++) {
      if (is(j, i)) {
        adj[cmp[j][i - 1]].push_back(cmp[j][i + 1]);
        adj[cmp[j][i + 1]].push_back(cmp[j][i - 1]);
      }
    }
  }
  bipartite();
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      if (A[j][i] == 0) {
        if (color[cmp[j][i]] % 2 == i % 2) {
          out[j][i] = 4;
        } else
          out[j][i] = 1;
      }
    }
  }
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      if (A[j][i]) {
        long long int c = 0;
        c += out[j - 1][i] * (A[j - 1][i] == 0);
        c += out[j + 1][i] * (A[j + 1][i] == 0);
        c += out[j][i - 1] * (A[j][i - 1] == 0);
        c += out[j][i + 1] * (A[j][i + 1] == 0);
        out[j][i] = c;
        assert(c % 5 == 0);
      }
    }
  }
  for (long long int j = 1; j <= n; j++) {
    for (long long int i = 1; i <= m; i++) {
      cout << out[j][i] << ' ';
    }
    cout << '\n';
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  for (long long int j = 1; j <= MAX * MAX; j++) color[j] = -1;
  while (t--) {
    solve();
  }
  return 0;
}
