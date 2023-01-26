#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
const long long MOD = 998244353;
int sign(double x, double y) {
  if (fabs(x - y) < 1e-12) return 0;
  if (x - y > 1e-12)
    return 1;
  else
    return -1;
}
long long quickPow(long long a, long long b) {
  long long res = 1;
  for (a %= MOD; b; b >>= 1) {
    if (b & 1) res = (res * a) % MOD;
    a = a * a % MOD;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long inv(long long x) { return quickPow(x, MOD - 2); }
int lowbit(int x) { return x & (-x); }
const int N = 2e3 + 10;
int n, m;
int row, col, ans;
string s[N];
int ind[N][N], val[N][N];
bool vis[N][N];
queue<pair<int, int> > q;
bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
bool check(pair<int, int> node) { return check(node.first, node.second); }
pair<int, int> move(pair<int, int> node, char dir) {
  if (dir == 'U') return {node.first - 1, node.second};
  if (dir == 'D') return {node.first + 1, node.second};
  if (dir == 'L') return {node.first, node.second - 1};
  if (dir == 'R') return {node.first, node.second + 1};
}
int dfs(int x, int y) {
  if (!check(x, y)) return 0;
  if (val[x][y]) return val[x][y];
  pair<int, int> nxt = move({x, y}, s[x][y]);
  return val[x][y] = dfs(nxt.first, nxt.second) + 1;
}
int findCyc(int x, int y) {
  vis[x][y] = true;
  q.push({x, y});
  while (1) {
    pair<int, int> nxt = move({x, y}, s[x][y]);
    x = nxt.first, y = nxt.second;
    if (vis[x][y]) break;
    vis[x][y] = true;
    q.push({x, y});
  }
  int cycLen = q.size();
  while (q.size()) {
    pair<int, int> node = q.front();
    q.pop();
    val[node.first][node.second] = cycLen;
  }
  return cycLen;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cas;
  cin >> cas;
  while (cas--) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) vis[i][j] = ind[i][j] = val[i][j] = 0;
    while (q.size()) q.pop();
    ans = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = " " + s[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pair<int, int> nxt = move({i, j}, s[i][j]);
        if (!check(nxt)) continue;
        ind[nxt.first][nxt.second]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!ind[i][j]) {
          q.push({i, j});
        }
      }
    }
    while (q.size()) {
      pair<int, int> node = q.front();
      q.pop();
      vis[node.first][node.second] = true;
      pair<int, int> nxt = move(node, s[node.first][node.second]);
      if (!check(nxt)) continue;
      if (!--ind[nxt.first][nxt.second]) {
        q.push(nxt);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!vis[i][j]) {
          int tmp = findCyc(i, j);
          if (tmp > ans) ans = tmp, row = i, col = j;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!val[i][j]) {
          int tmp = dfs(i, j);
          if (tmp > ans) ans = tmp, row = i, col = j;
        }
      }
    }
    cout << row << ' ' << col << ' ' << ans << '\n';
  }
  return 0;
}
