#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
bool valid(long long i, long long j) {
  if (i >= 0 && i < n && j >= 0 && j < m) {
    return true;
  }
  return false;
}
void bfs(long long i, long long j, vector<vector<char>> &v) {
  queue<pair<long long, long long>> q;
  q.push({i, j});
  while (!q.empty()) {
    long long curx = q.front().first;
    long long cury = q.front().second;
    q.pop();
    long long cnt[2] = {0, 0};
    for (long long k = 0; k < 4; k++) {
      long long x = curx + dx[k];
      long long y = cury + dy[k];
      if (valid(x, y) && v[x][y] != '#') {
        cnt[0] += (v[x][y] == '.');
        cnt[1] += (v[x][y] == '+' || v[x][y] == 'L');
      }
    }
    if (cnt[0] >= 2 && cnt[1] != 0) continue;
    v[curx][cury] = '+';
    for (long long k = 0; k < 4; k++) {
      long long x = curx + dx[k];
      long long y = cury + dy[k];
      if (valid(x, y) && v[x][y] == '.') {
        q.push({x, y});
      }
    }
  }
}
void play() {
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  long long x, y;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> v[i][j];
      if (v[i][j] == 'L') x = i, y = j;
    }
  }
  bfs(x, y, v);
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
