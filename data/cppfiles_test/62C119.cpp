#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = INT64_MAX;
const long long MAX = 1000;
pair<long long, long long> adj[MAX][MAX][2];
vector<set<long long>> ds[2];
long long vis[MAX][MAX];
long long ans = 0, ctr = 0;
bool is_valid(long long i, long long j, long long n, long long m) {
  return (i >= 0 && i < n && j >= 0 && j < m);
}
long long fun(long long n) { return n * (n - 1) / 2; }
void initiate(long long n, long long m) {
  long long c1, c2;
  ctr = n * m;
  c1 = 1;
  memset(vis, 0, sizeof(vis));
  vector<pair<long long, long long>> offset = {{0, 1}, {1, 0}};
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!vis[i][j]) {
        c2 = 1;
        long long dir = (i % 2) ^ (j % 2);
        long long ti = i;
        long long tj = j;
        do {
          vis[ti][tj] = 1;
          adj[ti][tj][0] = {c1, c2};
          c2++;
          ti += offset[dir].first;
          tj += offset[dir].second;
          dir ^= 1;
        } while (is_valid(ti, tj, n, m) && !vis[ti][tj]);
        c1++;
        c2--;
        set<long long> t = {0, c2 + 1};
        ds[0].push_back(t);
        ans += fun(c2);
      }
    }
  }
  c1 = 1;
  memset(vis, 0, sizeof(vis));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!vis[i][j]) {
        c2 = 1;
        long long dir = (i % 2) ^ (1 - j % 2);
        long long ti = i;
        long long tj = j;
        do {
          vis[ti][tj] = 1;
          adj[ti][tj][1] = {c1, c2};
          c2++;
          ti += offset[dir].first;
          tj += offset[dir].second;
          dir ^= 1;
        } while (is_valid(ti, tj, n, m) && !vis[ti][tj]);
        c1++;
        c2--;
        set<long long> t = {0, c2 + 1};
        ds[1].push_back(t);
        ans += fun(c2);
      }
    }
  }
}
void query(long long x, long long y, long long c) {
  long long c1 = adj[x][y][c].first;
  long long c2 = adj[x][y][c].second;
  c1--;
  if (vis[x][y]) {
    ds[c][c1].erase(c2);
  }
  auto it = ds[c][c1].lower_bound(c2);
  it--;
  long long l = *it;
  it = ds[c][c1].upper_bound(c2);
  long long r = *it;
  long long diff = fun(r - l - 1) - fun(c2 - l - 1) - fun(r - c2 - 1);
  if (vis[x][y]) {
    ans += diff;
  } else {
    ans -= diff;
  }
  if (!vis[x][y]) {
    ds[c][c1].insert(c2);
  }
}
void solve() {
  long long n, m, q, x, y;
  cin >> n >> m >> q;
  initiate(n, m);
  memset(vis, 0, sizeof(vis));
  for (long long i = 0; i < q; i++) {
    cin >> x >> y;
    x--;
    y--;
    query(x, y, 0);
    query(x, y, 1);
    vis[x][y] = 1 - vis[x][y];
    if (vis[x][y]) {
      ctr--;
    } else {
      ctr++;
    }
    cout << ans + ctr << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  for (int i = 1; i <= test; i++) {
    solve();
  }
  return 0;
}
