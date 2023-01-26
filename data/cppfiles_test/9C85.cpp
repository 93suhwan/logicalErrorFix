#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m, k;
int calAns = 0;
int mx[maxn][maxn];
int ans[maxn];
int dx[4] = {-1, 0, +1, 0};
int dy[4] = {-1, +1, 0, -1};
void go(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m) {
    calAns = y;
    return;
  }
  int cur = mx[x][y];
  mx[x][y] = 2;
  int nxX = x + dx[cur];
  int nxY = y + dy[cur];
  if (nxX <= 0 || nxX > n || nxY <= 0 || nxY > m) {
    calAns = y;
    return;
  } else {
    go(nxX, nxY);
  }
}
int cal(int col) {
  go(1, col);
  return calAns;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mx[i][j];
    }
  }
  vector<int> c(k);
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < k; i++) {
    ans[c[i]] = cal(c[i]);
    cout << ans[c[i]] << " ";
  }
}
