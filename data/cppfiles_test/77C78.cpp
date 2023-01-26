#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const long long lnf = 1e18 + 7;
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int main(void) {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> map(n + 1, vector<int>(m + 1));
  vector<vector<int>> vst(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
    }
  }
  queue<pair<int, int>> qu;
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vst[i][j]) {
        vst[i][j] = 1;
        qu.push({i, j});
        int cnt = 0;
        while (!qu.empty()) {
          pair<int, int> cur = qu.front();
          qu.pop();
          cnt++;
          for (int d = 0; d < 4; d++) {
            if (!(map[cur.first][cur.second] & (1 << d))) {
              int ny = cur.first + dir[d][0];
              int nx = cur.second + dir[d][1];
              if (!vst[ny][nx] && !(map[ny][nx] & (1 << ((d + 2) % 4)))) {
                vst[ny][nx] = 1;
                qu.push({ny, nx});
              }
            }
          }
        }
        pq.push(cnt);
      }
    }
  }
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  return 0;
}
