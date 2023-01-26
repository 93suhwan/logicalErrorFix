#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 200005;
string s, p;
long long upCount[1005][1005], leftCount[1005][1005], a[1005][1005], n, m, q;
long long dfs(int x, int y, int f) {
  if (x == 0 || y == 0 || a[x][y]) return 0;
  if (f) {
    return 1 + dfs(x - 1, y, f ^ 1);
  } else {
    return 1 + dfs(x, y - 1, f ^ 1);
  }
}
long long dfs2(int x, int y, int f) {
  if (x > n || y > m || a[x][y]) return 0;
  if (f) {
    return 1 + dfs2(x + 1, y, f ^ 1);
  } else {
    return 1 + dfs2(x, y + 1, f ^ 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      leftCount[i][j] = upCount[i][j - 1] + 1;
      upCount[i][j] = leftCount[i - 1][j] + 1;
      res += leftCount[i][j];
      res += upCount[i][j];
      res -= 1;
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    long long up = dfs(x - 1, y, 0);
    long long down = dfs2(x + 1, y, 0);
    long long lft = dfs(x, y - 1, 1);
    long long rgt = dfs2(x, y + 1, 1);
    if (a[x][y]) {
      res += (up + 1) * (rgt + 1);
      res += (lft + 1) * (down + 1);
      res -= 1;
    } else {
      res -= (up + 1) * (rgt + 1);
      res -= (lft + 1) * (down + 1);
      res += 1;
    }
    a[x][y] ^= 1;
    cout << res << "\n";
  }
  return 0;
}
