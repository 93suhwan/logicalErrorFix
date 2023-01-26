#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e3 + 5, mod = 1e9 + 7, inf = 1e9;
const long double pi = 4 * atan(1.0), eps = 1e-9;
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tc = 1;
  for (long long test = (long long)(1); test <= (long long)(tc); ++test) {
    solve();
  }
  return 0;
}
bool mark[maxn][maxn];
long long ans[maxn][maxn];
long long n, m;
long long c[1 << 20];
vector<long long> g[1 << 20];
void dfs(long long i) {
  for (long long j : g[i]) {
    if (c[j] == -1) {
      c[j] = c[i] ^ 1;
      dfs(j);
    }
  }
}
long long conv(long long i, long long j) { return i * m + j; }
void add(long long i, long long j) {
  g[i].emplace_back(j);
  g[j].emplace_back(i);
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
void solve() {
  cin >> n >> m;
  fill(begin(c), end(c), -1);
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i)
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j) {
      char c;
      cin >> c;
      if (c == 'X') mark[i][j] = 1;
    }
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i)
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j) {
      if (mark[i][j]) {
        for (long long x = (long long)(i - 1); x <= (long long)(i + 1); ++x)
          for (long long y = (long long)(j - 1); y <= (long long)(j + 1); ++y) {
            vector<pair<long long, long long> > unmarked;
            long long dir = 0;
            for (long long d = (long long)(0); d <= (long long)(3); ++d) {
              long long x = i + dx[d], y = j + dy[d];
              if (!mark[x][y]) {
                dir++;
                unmarked.emplace_back(x, y);
              }
            }
            if (dir & 1) {
              cout << "NO";
              return;
            }
            if (dir == 0)
              continue;
            else if (dir == 2) {
              add(conv(unmarked[0].first, unmarked[0].second),
                  conv(unmarked[1].first, unmarked[1].second));
            } else {
              add(conv(i - 1, j), conv(i, j - 1));
              add(conv(i + 1, j), conv(i, j - 1));
              add(conv(i + 1, j), conv(i, j + 1));
            }
          }
      }
    }
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i) {
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j) {
      if (c[conv(i, j)] == -1 and !mark[i][j]) {
        c[conv(i, j)] = 0;
        dfs(conv(i, j));
      }
    }
  }
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i) {
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j) {
      if (c[conv(i, j)] >= 0) ans[i][j] = c[conv(i, j)] == 0 ? 1 : 4;
    }
  }
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i) {
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j) {
      if (mark[i][j]) {
        for (long long d = (long long)(0); d <= (long long)(3); ++d) {
          long long x = i + dx[d], y = j + dy[d];
          if (!mark[x][y]) ans[i][j] += ans[x][y];
        }
        assert(ans[i][j] % 5 == 0);
      }
    }
  }
  cout << "YES" << '\n';
  for (long long i = (long long)(0); i <= (long long)(n - 1); ++i) {
    for (long long j = (long long)(0); j <= (long long)(m - 1); ++j)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
}
