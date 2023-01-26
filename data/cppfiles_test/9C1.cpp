#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int a[1005][1005];
int n, m, k;
int dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return y;
  if (a[x][y] == 1) {
    a[x][y] = 2;
    return dfs(x, y + 1);
  } else if (a[x][y] == 2) {
    return dfs(x + 1, y);
  } else {
    a[x][y] = 2;
    return dfs(x, y - 1);
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  while (k--) {
    int c;
    cin >> c;
    cout << dfs(1, c) << " ";
  }
  cout << endl;
  return 0;
}
