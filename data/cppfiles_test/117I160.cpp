#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
bool valid(long long i, long long j, vector<vector<bool>> &vis,
           vector<vector<char>> &v) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    return true;
  }
  return false;
}
void bfs(long long i, long long j, vector<vector<bool>> &vis,
         vector<vector<char>> &v) {
  queue<pair<long long, long long>> q;
  q.push({i, j});
  vis[i][j] = 1;
  while (!q.empty()) {
    long long curx = q.front().first;
    long long cury = q.front().second;
    q.pop();
    long long cnt = 0;
    for (long long k = 0; k < 4; k++) {
      long long x = curx + dx[k];
      long long y = cury + dy[k];
      if (valid(x, y, vis, v) && v[x][y] != '#') {
        cnt++;
      }
    }
    if (cnt > 2) continue;
    v[curx][cury] = '+';
    for (long long k = 0; k < 4; k++) {
      long long x = curx + dx[k];
      long long y = cury + dy[k];
      if (valid(x, y, vis, v) && v[x][y] == '.' && vis[x][y] == 0) {
        q.push({x, y});
        vis[x][y] = 1;
      }
    }
  }
}
void play() {
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  long long x, y;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'L') x = i, y = j;
    }
  }
  bfs(x, y, vis, v);
  v[x][y] = 'L';
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cout << v[i][j];
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  for (long long i = 1; i < t + 1; i++) {
    play();
  }
  return 0;
}
