#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
vector<vector<long long> > adj;
long long color[1000005];
bool v[1000005] = {0};
long long block(long long x, long long y, long long m) { return m * x + y; }
void dfs(long long idx, long long y) {
  v[idx] = 1;
  color[idx] = y;
  for (auto x : adj[idx]) {
    if (!v[x]) {
      dfs(x, y ^ 1);
    } else if (v[x]) {
      assert(color[x] == (y ^ 1));
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  char arr[n][m];
  long long ans[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  bool ok = 1;
  long long ola = n * m + 10;
  adj.assign(ola, vector<long long>());
  long long dx[4] = {0, 0, 1, -1};
  long long dy[4] = {1, -1, 0, 0};
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == 'X') {
        long long posa = 0;
        vector<long long> ex;
        for (long long k = 0; k < 4; k++) {
          long long x = i + dx[k], y = dy[k] + j;
          if (arr[x][y] == '.') {
            ex.push_back(block(x, y, m));
            posa++;
          }
        }
        if (posa == 2) {
          for (long long i = 0; i < posa; i++) {
            adj[ex[i]].push_back(ex[(i + 1) % posa]);
            adj[ex[(i + 1) % posa]].push_back(ex[i]);
          }
        } else if (posa == 4) {
          adj[ex[0]].push_back(ex[3]);
          adj[ex[3]].push_back(ex[0]);
          adj[ex[2]].push_back(ex[1]);
          adj[ex[1]].push_back(ex[2]);
        }
        if (posa % 2) {
          ok = 0;
        }
      }
    }
  }
  if (!ok) {
    cout << "NO";
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == '.' && !v[block(i, j, m)]) {
        dfs(block(i, j, m), 0);
      }
      if (arr[i][j] == '.') {
        ans[i][j] = 1;
        if (color[block(i, j, m)] == 1) {
          ans[i][j] = 4;
        }
      }
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (arr[i][j] == 'X') {
        ans[i][j] = 0;
        for (long long k = 0; k < 4; k++) {
          long long x = i + dx[k], y = dy[k] + j;
          if (arr[x][y] == '.') {
            ans[i][j] += ans[x][y];
          }
        }
      }
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
