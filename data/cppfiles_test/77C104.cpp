#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int cnt;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool check(int x, int y) {
  if (vis[x][y] || x < 1 || x > n || y < 1 || y > m) return false;
  return true;
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int p = a[x][y] >> (3 - i) & 1;
    if (p) continue;
    int nowx = x + dx[i], nowy = y + dy[i];
    if (check(nowx, nowy)) dfs(nowx, nowy);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  vector<int> V;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        V.push_back(cnt);
      }
    }
  }
  sort(V.begin(), V.end());
  for (int i = V.size() - 1; i >= 0; i--) {
    cout << V[i] << ' ';
  }
}
