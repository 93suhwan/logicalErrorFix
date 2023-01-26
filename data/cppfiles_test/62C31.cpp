#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, Q;
long long ans, cnt, f[N][N][2];
bool vis[N][N];
void update(int i, int j) {
  if (j < 1 || j > m) return;
  ans -= (f[i][j][0] + f[i][j][1]);
  if (vis[i][j])
    f[i][j][0] = f[i][j][1] = 0;
  else
    f[i][j][0] = f[i][j + 1][1] + 1, f[i][j][1] = f[i + 1][j][0] + 1;
  ans += (f[i][j][0] + f[i][j][1]);
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) update(i, j), cnt++;
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x][y] ^= 1;
    if (vis[x][y] == 1)
      cnt--;
    else
      cnt++;
    for (int i = x, j = y - 1; i >= 1; i--, j--)
      update(i, j + 2), update(i, j + 1), update(i, j);
    cout << ans - cnt << "\n";
  }
  return 0;
}
