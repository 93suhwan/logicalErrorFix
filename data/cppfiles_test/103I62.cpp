#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, N = 2002;
long long cnt, n, m;
char c[N][N];
long long vis[N][N], res[N][N];
bool ok;
string s;
bool check(char a, char b) {
  if (a > b) swap(a, b);
  if (a == 'L' && b == 'R') return 1;
  if (a == 'D' && b == 'U') return 1;
  return 0;
}
void dfs(long long i, long long j) {
  vis[i][j] = cnt;
  long long x = j, y = i;
  if (c[i][j] == 'L') x--;
  if (c[i][j] == 'R') x++;
  if (c[i][j] == 'D') y++;
  if (c[i][j] == 'U') y--;
  if (x > m || x < 1 || y > n || y < 1 || vis[y][x] == vis[i][j])
    res[i][j] = 1;
  else if (check(c[i][j], c[y][x]))
    res[i][j] = 2;
  else if (vis[y][x] != 0)
    res[i][j] = res[y][x] + 1;
  else {
    dfs(y, x);
    res[i][j] = res[y][x] + 1;
  }
}
struct ans {
  long long ax, ay, aw;
} as;
void solve() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> c[i][j];
  cnt = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (vis[i][j] == 0) {
        cnt++;
        vis[i][j] = cnt;
        dfs(i, j);
      }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      if (res[i][j] > as.aw) {
        as.ax = i;
        as.ay = j;
        as.aw = res[i][j];
      }
  cout << as.ax << " " << as.ay << " " << as.aw;
  as.ax = as.ay = as.aw = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) vis[i][j] = res[i][j] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tttt = 1;
  cin >> tttt;
  while (tttt--) {
    solve();
    cout << endl;
  }
  cerr << "\n" << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms";
}
