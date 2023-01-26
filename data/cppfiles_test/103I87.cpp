#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
const int mod = 1e9 + 7, N = 2e3 + 10;
char mp[N][N];
int f[N][N];
bool st[N][N];
unordered_map<char, pair<int, int>> mv = {
    {'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n, m, tx, ty;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", &mp[i][1]);
    stack<pair<int, int>> q;
    for (int i = 0; i <= n + 1; i++)
      for (int j = 0; j <= m + 1; j++) f[i][j] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x = i, y = j;
        bool ring = false;
        if (f[x][y] != 1) continue;
        do {
          q.push({x, y});
          st[x][y] = true;
          tx = x + mv[mp[x][y]].first, ty = y + mv[mp[x][y]].second;
          x = tx, y = ty;
          if (x < 1 || x > n || y < 1 || y > m) break;
          if (st[x][y]) {
            cout << x << ' ' << y << endl;
            ring = true;
            break;
          }
          if (f[x][y] != 1) {
            q.push({x, y});
            break;
          }
        } while (true);
        pair<int, int> xy;
        int step;
        if (ring) {
          stack<pair<int, int>> rq;
          do {
            xy = q.top();
            q.pop();
            rq.push(xy);
            if (xy.first == x && xy.second == y) break;
          } while (true);
          step = rq.size();
          while (rq.size()) {
            xy = rq.top();
            rq.pop();
            f[xy.first][xy.second] = step;
          }
          step++;
          while (q.size()) {
            xy = q.top();
            q.pop();
            f[xy.first][xy.second] = step++;
          }
          memset(st, false, sizeof(st));
          continue;
        }
        step = f[q.top().first][q.top().second];
        while (q.size()) {
          xy = q.top();
          q.pop();
          f[xy.first][xy.second] = step++;
        }
        memset(st, false, sizeof(st));
      }
    }
    int res = -1, x, y;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (res < f[i][j]) {
          x = i, y = j;
          res = f[i][j];
        }
      }
    }
    cout << x << ' ' << y << ' ' << res << endl;
  }
  return 0;
}
