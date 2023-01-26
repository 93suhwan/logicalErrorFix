#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e3 + 1;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int n, m;
char a[N][N];
int ans[N][N];
int vis[N][N], step;
int incyc, cyclen;
pair<int, int> cycp;
void dfs(int x, int y) {
  vis[x][y] = ++step;
  int xt = x;
  int yt = y;
  if (a[x][y] == 'U') xt--;
  if (a[x][y] == 'D') xt++;
  if (a[x][y] == 'L') yt--;
  if (a[x][y] == 'R') yt++;
  if ((1 > xt) || (xt > n) || (1 > yt) || (yt > m)) {
    ans[x][y] = 1;
    return;
  }
  if (vis[xt][yt]) {
    incyc = 1;
    cyclen = vis[x][y] - vis[xt][yt] + 1;
    vis[xt][yt] = 0;
    vis[x][y] = 0;
    ans[x][y] = cyclen;
    return;
  }
  if (!ans[xt][yt]) {
    dfs(xt, yt);
  }
  if (incyc)
    ans[x][y] = cyclen;
  else
    ans[x][y] = ans[xt][yt] + 1;
  if (vis[x][y] == 0) incyc = 0;
  vis[x][y] = 0;
}
void main0() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        ans[i][j] = vis[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        step = 0;
        dfs(i, j);
      }
    }
    pair<int, int> pos = {1, 1};
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (ans[i][j] > ans[pos.first][pos.second]) pos = {i, j};
      }
    }
    cout << pos.first << ' ' << pos.second << ' ' << ans[pos.first][pos.second]
         << endl;
  }
}
