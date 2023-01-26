#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class type>
type MODEXPO(type a, type b, int mod) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return MODEXPO((a * a) % mod, b / 2, mod);
  else
    return (a * MODEXPO((a * a) % mod, (b - 1) / 2, mod)) % mod;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long _INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e3 + 5;
const char dc[4] = {'D', 'R', 'U', 'L'};
int n, m, cnt;
int mat[N][N], vis[N][N];
int dx4[4] = {0, 1, 0, -1};
int dy4[4] = {-1, 0, 1, 0};
bool b(int x, int y, int i) {
  int t = mat[x][y];
  return !(1 & t >> i);
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int tmp = b(x, y, i);
    if (tmp) {
      int nx = x + dx4[i];
      int ny = y + dy4[i];
      if (nx >= 0 and nx < n and ny >= 0 and ny < m and vis[nx][ny] == 0)
        dfs(nx, ny);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      vis[i][j] = 0;
    }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt = 0;
      if (vis[i][j] == 0) {
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for (auto i : ans) {
    cout << i << " ";
  }
}
int main() {
  fast();
  solve();
  return 0;
}
