#include <bits/stdc++.h>
using namespace std;
const long long N = 505;
long long n, m;
char a[N][N];
long long ans[N][N];
long long dx[4] = {0, 0, -1, +1};
long long dy[4] = {+1, -1, 0, 0};
long long get(long long x, long long y) { return (x - 1) * m + y; }
vector<long long> g[N * N];
long long col[N * N];
bool vis[N * N];
void dfs(long long u, long long c) {
  if (vis[u]) {
    if (col[u] != c) {
      cout << "NO"
           << "\n";
      exit(0);
    }
    return;
  }
  vis[u] = 1;
  col[u] = c;
  for (auto &it : g[u]) dfs(it, c ^ 1);
}
bool check() {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (a[i][j] == 'X') {
        long long ct = 0;
        vector<pair<long long, long long> > v;
        for (long long dir = 0; dir < 4; dir++) {
          long long nx = i + dx[dir];
          long long ny = j + dy[dir];
          if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
          if (a[nx][ny] == 'X')
            ct++;
          else
            v.push_back({nx, ny});
        }
        if (v.size() >= 2) {
          long long idx = v.size() == 2 ? 1 : 2;
          long long uu = get(v[0].first, v[0].second);
          long long vv = get(v[idx].first, v[idx].second);
          g[uu].push_back(vv);
          g[vv].push_back(uu);
        }
        if (v.size() == 4) {
          long long uu = get(v[1].first, v[1].second);
          long long vv = get(v[3].first, v[3].second);
          g[uu].push_back(vv);
          g[vv].push_back(uu);
        }
        if (ct == 3 || ct == 1) {
          cout << "NO"
               << "\n";
          exit(0);
        } else if (ct == 4)
          ans[i][j] = 0;
        else if (ct == 0)
          ans[i][j] = 10;
        else
          ans[i][j] = 5;
      }
    }
  }
  for (long long i = 1; i <= n * m; i++) {
    if (vis[i]) continue;
    if (g[i].size()) dfs(i, 0);
  }
}
void print() {
  cout << "YES"
       << "\n";
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (!ans[i][j] && a[i][j] != 'X') ans[i][j] = 1;
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  }
  check();
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (vis[get(i, j)]) {
        ans[i][j] = col[get(i, j)] ? 4 : 1;
      }
    }
  }
  print();
  return 0;
}
