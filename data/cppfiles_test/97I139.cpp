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
int vis[505][505] = {0};
int num;
int cut[250005];
int cn = 0;
pair<int, int> p[250005];
int judge(int x, int y, int t) {
  t = 3 * t + 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx > 0 && nx < n && ny > 0 && ny < m) {
      if (v[nx][ny] == 2 && ans[nx][ny] == t)
        return 0;
      else if (v[nx][ny] == 4) {
        if (t == 4 && ans[nx][ny] > 7) return 0;
        if (t == 1)
          if (ans[nx][ny] == 2 || ans[nx][ny] == 6) return 0;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (s[nx][ny] == 'X')
      if (nx > 0 && nx < n && ny > 0 && ny < m) ans[nx][ny] += t;
  }
  s[x][y] = '0' + t;
  return 1;
}
struct node {
  int x, y, t;
};
stack<node> st;
int dis[505][505] = {0};
int dfs() {
  int pos = num - 1;
  clock_t begin = clock();
  int nowt, last = 10;
  while (pos >= 0) {
    int x = p[pos].first, y = p[pos].second, t;
    if (n == 499) {
      nowt = (clock() - begin);
      if (nowt > last) {
        printf("%d %d\n", nowt, pos);
        last = nowt + 30;
      }
    }
    if (clock() - begin > 2005) break;
    if (!dis[x][y]) {
      dis[x][y] = (pos & 1) + 1;
      t = dis[x][y] - 1;
      if (judge(x, y, t)) {
        st.push({x, y, t});
        pos--;
        continue;
      }
    }
    if (dis[x][y] != 3) {
      t = 2 - dis[x][y];
      dis[x][y] = 3;
      if (judge(x, y, t)) {
        st.push({x, y, t});
        pos--;
        continue;
      }
    }
    dis[x][y] = 0;
    pos++;
    if (st.empty()) break;
    node r = st.top();
    st.pop();
    t = r.t, x = r.x, y = r.y;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx > 0 && nx < n && ny > 0 && ny < m)
        if (s[nx][ny] == 'X') ans[nx][ny] -= t * 3 + 1;
    }
  }
  if (n == 499) printf("pos %d num %d\n", pos, num), pos = -1;
  return pos == -1;
}
void predfs(int x, int y) {
  vis[x][y] = 1;
  p[num++] = pair<int, int>(x, y);
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (s[nx][ny] == 'X') {
      for (int j = 0; j < 4; j++) {
        int nnx = nx + dx[j], nny = ny + dy[j];
        if (s[nnx][nny] == '.' && !vis[nnx][nny]) predfs(nnx, nny);
      }
    }
  }
}
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
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!vis[i][j] && s[i][j] == '.') predfs(i, j);
  if (flag) flag = dfs();
  if (!flag) {
    puts("NO\n");
    return;
  }
  puts("YES");
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
