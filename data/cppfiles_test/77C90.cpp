#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e3 + 100;
long long a[N][N], vis[N][N], tot = 0;
long long x[] = {0, 1, 0, -1};
long long y[] = {-1, 0, 1, 0};
long long n, m;
map<long long, long long> mp;
void dfs(long long u, long long v) {
  if (vis[u][v]) return;
  vis[u][v] = tot;
  for (long long i = 0; i <= 3; i++) {
    long long p = a[u][v] >> i;
    if (!(p & 1) && u + x[i] <= n && u + x[i] >= 1 && v + y[i] <= m &&
        v + y[i] >= 1) {
      dfs(u + x[i], v + y[i]);
    }
  }
}
void print() {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cout << vis[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (vis[i][j] != 0) continue;
      tot++;
      dfs(i, j);
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      mp[vis[i][j]]++;
    }
  }
  vector<long long> ve;
  for (auto q : mp) ve.push_back(q.second);
  sort(ve.begin(), ve.end(), greater<long long>());
  for (auto X : ve) cout << X << " ";
}
