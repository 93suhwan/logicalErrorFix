#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
long long n, m, ans[510][510];
char grid[510][510];
vector<long long> vt[510 * 510];
void dfs(long long x, long long v) {
  ans[x / m][x % m] = v;
  long long i;
  for (i = 0; i < vt[x].size(); i++) {
    if (ans[vt[x][i] / m][vt[x][i] % m] == -1) {
      dfs(vt[x][i], 5 - v);
    }
  }
  return;
}
int main() {
  long long i, j, k, x, y;
  scanf("%lld%lld", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", &grid[i]);
  }
  memset(ans, -1, sizeof(ans));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        continue;
      }
      vector<long long> adj;
      for (k = 0; k < 4; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (grid[x][y] == '.') {
          adj.push_back(x * m + y);
        }
      }
      if (adj.size() == 0) {
        ans[i][j] = 0;
      } else if (adj.size() == 2) {
        vt[adj[0]].push_back(adj[1]);
        vt[adj[1]].push_back(adj[0]);
      } else if (adj.size() == 4) {
        vt[adj[0]].push_back(adj[1]);
        vt[adj[1]].push_back(adj[0]);
        vt[adj[2]].push_back(adj[3]);
        vt[adj[3]].push_back(adj[2]);
      } else {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ans[i][j] == -1 && grid[i][j] == '.') {
        dfs(i * m + j, 1);
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ans[i][j] == -1) {
        ans[i][j] = 0;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (grid[i][j] == 'X') {
        for (k = 0; k < 4; k++) {
          x = i + dx[k];
          y = j + dy[k];
          if (grid[x][y] == '.') {
            ans[i][j] += ans[x][y];
          }
        }
      }
      printf("%lld ", ans[i][j]);
    }
    puts("");
  }
  return 0;
}
