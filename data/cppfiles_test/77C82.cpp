#include <bits/stdc++.h>
using namespace std;
long long dx[] = {0, 1, 0, -1};
long long dy[] = {-1, 0, 1, 0};
long long rec[] = {2, 3, 0, 1};
vector<vector<long long>> g;
int n, m;
vector<long long> compsize;
vector<vector<long long>> comp;
vector<vector<long long>> comp1;
bool valid(long long x, long long y) {
  if (x < 0 || y < 0 || x >= n || y >= m) {
    return false;
  }
  return true;
}
void dfs(long long compno, long long x, long long y) {
  comp[x][y] = compno;
  compsize[compno]++;
  for (long long i = 0; i < 4; i++) {
    long long x1 = x + dx[i];
    long long y1 = y + dy[i];
    if (valid(x1, y1) && comp[x1][y1] == 0 && (g[x][y] & (1 << i)) == 0 &&
        (g[x1][y1] & (1 << rec[i])) == 0) {
      dfs(compno, x1, y1);
    }
  }
}
void solve() {
  cin >> n >> m;
  g = vector<vector<long long>>(n, vector<long long>(m));
  comp = vector<vector<long long>>(n, vector<long long>(m, 0));
  comp1 = vector<vector<long long>>(n, vector<long long>(m, 0));
  compsize = vector<long long>(n * m + 1, 0);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  long long compno = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (comp[i][j] == 0) {
        dfs(compno, i, j);
        compno++;
      }
    }
  }
  sort(compsize.begin(), compsize.end(), greater<long long>());
  for (long long i = 0; i <= n * m; i++) {
    if (compsize[i] == 0) {
      break;
    }
    cout << compsize[i] << " ";
  }
  cout << endl;
}
int main() {
  solve();
  return 0;
}
