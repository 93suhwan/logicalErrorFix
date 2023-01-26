#include <bits/stdc++.h>
template <class T>
long long sqr(T a) {
  return 1LL * a * a;
}
template <class T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(all(a)) - a.begin());
}
using namespace std;
const int N = 1e3 + 10;
const int M = log2(N) + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long INFI = 1e18;
const double long pi = acos(-1.00);
const double long eps = 1e-9;
int dist[N][N], dp[N][N], sta[N][N], n, m, q, res = 0;
int calc(int x, int y, int z) {
  if (y > z) {
    swap(y, z);
  }
  if (x <= y) {
    if (!x) {
      return 0;
    }
    return (4 * x - 1);
  }
  if (z < x) {
    return (4 * y + 1 + 2 * (z - y));
  }
  return (4 * y + 1 + 2 * (x - y - 1) + 1);
}
void update_dp(int x, int y) {
  for (int i = 0; i < min(n, m); i++) {
    if (x - i > 0 && y - i > 0) {
      int cur = dp[x - i][y - i];
      dp[x - i][y - i] = calc(dist[x - i][y - i], dist[x - i + 1][y - i],
                              dist[x - i][y - i + 1]);
      res += dp[x - i][y - i] - cur;
    }
    if (x - i - 1 > 0 && y - i > 0) {
      int cur = dp[x - i - 1][y - i];
      dp[x - i - 1][y - i] = calc(dist[x - i - 1][y - i], dist[x - i][y - i],
                                  dist[x - i - 1][y - i + 1]);
      res += dp[x - i - 1][y - i] - cur;
    }
    if (x - i > 0 && y - i - 1 > 0) {
      int cur = dp[x - i][y - i - 1];
      dp[x - i][y - i - 1] =
          calc(dist[x - i][y - i - 1], dist[x - i + 1][y - i - 1],
               dist[x - i][y - i]);
      res += dp[x - i][y - i - 1] - cur;
    }
  }
}
void update_0(int x, int y) {
  for (int i = 0; i < min(n, m); i++) {
    if (x == i || y == i) {
      break;
    }
    if (dist[x - i][y - i] == i) {
      dist[x - i][y - i] = dist[x + 1][y + 1] + i + 1;
    }
  }
  update_dp(x, y);
}
void update_1(int x, int y) {
  for (int i = 0; i < min(n, m); i++) {
    if (x == i || y == i) {
      break;
    }
    dist[x - i][y - i] = min(dist[x - i][y - i], i);
  }
  update_dp(x, y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dist[i][j] = min(n - i, m - j) + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = calc(dist[i][j], dist[i + 1][j], dist[i][j + 1]);
      res += dp[i][j];
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    sta[x][y] ^= 1;
    if (!sta[x][y]) {
      update_0(x, y);
    } else {
      update_1(x, y);
    }
    cout << res << "\n";
  }
  return 0;
}
