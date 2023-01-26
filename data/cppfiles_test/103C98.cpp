#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll N = 2111;
ll start[N][N], in_loop[N][N], vis[N][N];
string maze[N];
pair<ll, ll> get_next_move(pair<ll, ll> cur) {
  int di = 0, dj = 0;
  if (maze[cur.first][cur.second] == 'L') dj = -1;
  if (maze[cur.first][cur.second] == 'R') dj = 1;
  if (maze[cur.first][cur.second] == 'U') di = -1;
  if (maze[cur.first][cur.second] == 'D') di = 1;
  return {cur.first + di, cur.second + dj};
}
void solve() {
  ll n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> maze[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      start[i][j] = in_loop[i][j] = vis[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0) {
        pair<ll, ll> cur_p = {i, j};
        queue<pair<ll, ll>> Q;
        int find_loop = 0;
        pair<ll, ll> loop_start;
        while (1) {
          Q.push(cur_p);
          vis[cur_p.first][cur_p.second] = 2;
          auto next_p = get_next_move(cur_p);
          if (0 <= next_p.first && next_p.first < n && next_p.second >= 0 &&
              next_p.second < m) {
            if (vis[next_p.first][next_p.second] == 1) {
              break;
            } else if (vis[next_p.first][next_p.second] == 2) {
              find_loop = 1;
              loop_start = next_p;
              break;
            } else {
              cur_p = next_p;
            }
          } else {
            find_loop = 0;
            break;
          }
        }
        if (find_loop) {
          int loop_length = 1;
          auto next_p = get_next_move(loop_start);
          while (next_p != loop_start) {
            next_p = get_next_move(next_p);
            loop_length++;
          }
          next_p = get_next_move(loop_start);
          in_loop[loop_start.first][loop_start.second] = loop_length;
          while (next_p != loop_start) {
            in_loop[next_p.first][next_p.second] = loop_length;
            next_p = get_next_move(next_p);
          }
        }
        while (!Q.empty()) {
          auto p = Q.front();
          Q.pop();
          vis[p.first][p.second] = 1;
        }
      }
    }
  }
  int ans = 1, x = 1, y = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (in_loop[i][j] > ans) {
        ans = in_loop[i][j];
        x = i + 1;
        y = j + 1;
      }
      auto np = get_next_move({i, j});
      if (0 <= np.first && np.first < n && np.second >= 0 && np.second < m) {
        start[np.first][np.second] = 1;
      }
      vis[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (start[i][j] == 1) continue;
      int c = 1;
      pair<ll, ll> cp = {i, j};
      while (1) {
        auto np = get_next_move(cp);
        if (0 <= np.first && np.first < n && np.second >= 0 && np.second < m) {
        } else {
          break;
        };
        if (in_loop[np.first][np.second]) {
          c += in_loop[np.first][np.second];
          break;
        }
        cp = np;
        c++;
      }
      if (c > ans) {
        ans = c;
        x = i + 1;
        y = j + 1;
      }
    }
  }
  cout << x << " " << y << " " << ans << endl;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
