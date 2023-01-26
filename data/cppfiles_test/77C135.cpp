#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int v[maxn][maxn];
int n, m;
int cnt, k;
int t[maxn];
vector<int> gg;
bool vis[maxn][maxn];
bool cmp(int x, int y) { return x > y; }
void dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return;
  }
  if (vis[x][y]) {
    return;
  }
  cnt++;
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    if (!((v[x][y] >> i) & 1)) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        gg.push_back(cnt);
      }
    }
  }
  sort(gg.begin(), gg.end());
  for (int i = gg.size() - 1; i >= 0; i--) {
    cout << gg[i] << " ";
  }
  cout << endl;
  return 0;
}
