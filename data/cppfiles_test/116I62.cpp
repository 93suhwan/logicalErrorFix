#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 3e5 + 9, mod = 998244353;
vector<long long> adj[N];
vector<long long> act_adj[N];
bool vis[N];
long long mark[N];
long long dfs(long long v) {
  long long ans = 1;
  vis[v] = 1;
  long long flag = 0;
  if (mark[v] == 2) {
    flag = 1;
  }
  for (long long x : adj[v]) {
    if (vis[x]) {
      continue;
    }
    long long cnt = dfs(x);
    if (cnt == 0) flag = 1;
    ans += cnt;
  }
  if (flag)
    return 0;
  else
    return ans;
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long rem[k];
  memset(rem, -1, sizeof(rem));
  vector<long long> v[n];
  for (long long i = 0; i < n; i++) {
    long long c;
    cin >> c;
    vector<long long> tmp;
    for (long long j = 0; j < c; j++) {
      long long x;
      cin >> x;
      tmp.push_back(x);
      rem[x - 1] = 0;
    }
    v[i] = tmp;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j < v[i].size(); j++) {
      long long x = v[i][j - 1];
      long long y = v[i][j];
      if (y == v[i][0]) {
        mark[y] = 2;
      }
      if (mark[y] == 1 && !(act_adj[x].size() == 1 && act_adj[x][0] == y)) {
        mark[y] = 2;
      }
      if (x == y) {
        mark[x] = 2;
      }
      if (act_adj[x].size() == 1) {
        if (act_adj[x][0] != y) {
          mark[x] = 2;
        }
      } else {
        act_adj[x].push_back(y);
      }
      if ((x != y) &&
          (mark[y] == 0 ||
           !(mark[y] == 1 && (act_adj[x].size() == 1 && act_adj[x][0] == y)))) {
        adj[x].push_back(y);
        adj[y].push_back(x);
      }
      if (mark[y] == 0) mark[y] = 1;
    }
  }
  vector<long long> p(m + 1, 0);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < v[i].size(); j++) {
      if (!vis[v[i][j]]) {
        long long cnt = dfs(v[i][j]);
        if (cnt <= m) {
          p[cnt]++;
        }
      }
    }
  }
  p[0] = 0;
  p[1] += (abs(accumulate(rem, rem + k, 0)));
  long long idx = -1;
  for (long long i = m; i >= 0; i--) {
    if (p[i] >= 1) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    cout << "0\n";
    return;
  }
  map<long long, long long> mp;
  for (long long i = 1; i <= m; i++) {
    if (p[i] > 0) mp[i] = p[i];
  }
  long long dp[m + 1];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (long long i = 1; i <= m; i++) {
    for (auto x : mp) {
      long long idx = x.first;
      long long val = x.second;
      if (idx > i) {
        break;
      }
      dp[i] += val * dp[i - idx] % mod;
      dp[i] %= mod;
    }
  }
  cout << dp[m] % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
}
