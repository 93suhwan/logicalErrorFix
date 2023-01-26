#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 998244353;
const double PI = acos(-1.0);
int n, m;
int g[N][N];
bool vis[N][N];
int cnt;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
void dfs(int x, int y) {
  int i;
  cnt++;
  vis[x][y] = false;
  for (i = 0; i < 4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
      if (!((g[x][y] >> i) & 1) && !((g[xx][yy] >> ((i + 2) % 4)) & 1) &&
          vis[xx][yy]) {
        dfs(xx, yy);
      }
    }
  }
  return;
}
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j;
  cin >> n >> m;
  ans.clear();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> g[i][j];
      vis[i][j] = true;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<int>());
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
