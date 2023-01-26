#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
long long dp[N][N][2];
int vis[N][N];
pair<int, int> d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
int main() {
  long long n, m, q;
  scanf("%lld%lld%lld", &n, &m, &q);
  long long ans = 0;
  memset(vis, -1, sizeof(vis));
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      vis[i][j] = 0;
      dp[i][j][0] = dp[i][j + 1][1] + 1;
      dp[i][j][1] = dp[i + 1][j][0] + 1;
      ans += dp[i][j][0] + dp[i][j][1] - 1;
    }
  while (q--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    vector<long long> v;
    for (int i = 0; i < 4; i++) {
      pair<int, int> now = make_pair(x, y);
      long long len = 1, id = i;
      while (1) {
        now = add(now, d[id]);
        id ^= 1;
        if (vis[now.first][now.second]) break;
        len++;
      }
      v.push_back(len);
    }
    long long tmp = v[0] * v[3] + v[1] * v[2] - 1;
    ans += (vis[x][y] ? tmp : -tmp);
    vis[x][y] ^= 1;
    printf("%lld\n", ans);
  }
}
