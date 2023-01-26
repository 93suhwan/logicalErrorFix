#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m, k;
char s[505][505];
int v[505][505] = {0};
int ans[505][505] = {0};
int num;
struct node {
  int x, y, c;
};
void show() {
  puts("show");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", v[i][j]);
    puts("");
  }
  puts("");
  for (int i = 0; i < n; i++) printf("%s\n", s[i]);
  puts("");
}
queue<pair<int, int> > q1;
queue<pair<int, int> > q2;
queue<pair<int, int> > q3;
void solve() {
  num = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int flag = 1;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int k = 0; k < 4; k++)
          if (s[i + dx[k]][j + dy[k]] == '.') cnt++;
        v[i][j] = cnt;
        if (cnt & 1) flag = 0;
        if (cnt) q2.push(pair<int, int>(i, j));
      }
    }
  if (!flag) {
    puts("NO\n");
    return;
  }
  puts("YES");
  while (!(q1.empty() && q2.empty() && q3.empty())) {
    while (!q1.empty()) {
      pair<int, int> p = q1.front();
      q1.pop();
      int x = p.first, y = p.second;
      if (!v[x][y]) continue;
      int t = 5 - ans[x][y] % 5;
      if (ans[x][y] == 2) t = 4;
      if (ans[x][y] == 8) t = 1;
      if (t != 1 && t != 4) printf("ERROR\n");
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (s[nx][ny] == '.') {
          s[nx][ny] = '0' + t;
          for (int j = 0; j < 4; j++) {
            int nnx = nx + dx[j], nny = ny + dy[j];
            if (nnx > 0 && nnx < n - 1 && nny > 0 && nny < m - 1) {
              if (s[nnx][nny] != 'X') continue;
              v[nnx][nny]--;
              ans[nnx][nny] += t;
              if (ans[nnx][nny] == 2) q1.push(pair<int, int>(nnx, nny));
              if (ans[nnx][nny] == 8) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 1) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 2) q2.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 3) q3.push(pair<int, int>(nnx, nny));
            }
          }
          break;
        }
      }
    }
    while (q1.empty() && !q2.empty()) {
      pair<int, int> p = q2.front();
      q2.pop();
      int x = p.first, y = p.second;
      if (v[x][y] != 2 && v[x][y] != 4) continue;
      int t = ans[x][y] == 2 ? 4 : 1;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (s[nx][ny] == '.') {
          s[nx][ny] = '0' + t;
          for (int j = 0; j < 4; j++) {
            int nnx = nx + dx[j], nny = ny + dy[j];
            if (nnx > 0 && nnx < n - 1 && nny > 0 && nny < m - 1) {
              if (s[nnx][nny] != 'X') continue;
              v[nnx][nny]--;
              ans[nnx][nny] += t;
              if (ans[nnx][nny] == 2) q1.push(pair<int, int>(nnx, nny));
              if (ans[nnx][nny] == 8) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 1) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 2) q2.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 3) q3.push(pair<int, int>(nnx, nny));
            }
          }
          break;
        }
      }
    }
    while (q1.empty() && q2.empty() && !q3.empty()) {
      pair<int, int> p = q3.front();
      q3.pop();
      int x = p.first, y = p.second;
      if (v[x][y] != 3) continue;
      int t = 5 - ans[x][y] % 5;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (s[nx][ny] == '.') {
          s[nx][ny] = '0' + t;
          for (int j = 0; j < 4; j++) {
            int nnx = nx + dx[j], nny = ny + dy[j];
            if (nnx > 0 && nnx < n - 1 && nny > 0 && nny < m - 1) {
              if (s[nnx][nny] != 'X') continue;
              v[nnx][nny]--;
              ans[nnx][nny] += t;
              if (ans[nnx][nny] == 2) q1.push(pair<int, int>(nnx, nny));
              if (ans[nnx][nny] == 8) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 1) q1.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 2) q2.push(pair<int, int>(nnx, nny));
              if (v[nnx][nny] == 3) q3.push(pair<int, int>(nnx, nny));
            }
          }
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '.') s[i][j] = '1';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int q = 0; q < 4; q++) {
          int nx = i + dx[q], ny = j + dy[q];
          if (s[nx][ny] != 'X') cnt += s[nx][ny] - '0';
        }
        ans[i][j] = cnt;
      } else
        ans[i][j] = s[i][j] - '0';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) printf(j < m - 1 ? "%d " : "%d\n", ans[i][j]);
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
