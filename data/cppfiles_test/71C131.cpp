#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long mpow(long long base, long long exp);
void ipgraph(long long n, long long m);
void dfs(long long u, long long par);
const long long N = 100005, M = 100005;
vector<long long> g[N];
long long a[N];
long long ans;
long long dp[100][10][2];
long long doit(string s, long long res, long long i, long long prevG,
               long long& k, map<long long, long long>& vis) {
  if (i == s.size() && k >= vis.size()) {
    return res;
  }
  if (k < vis.size()) return INT_MAX;
  if (dp[i][vis.size()][prevG] != -1) return dp[i][vis.size()][prevG];
  long long st = 0, j;
  if (!prevG) st = s[i] - '0';
  long long ans = INT_MAX;
  for (j = st; j <= 9; j++) {
    long long tmp = 0;
    if (prevG || j > s[i] - '0') {
      tmp = 1;
    }
    vis[j]++;
    ans = min(ans, doit(s, res * 10 + j, i + 1, tmp, k, vis));
    if (vis[j] == 1)
      vis.erase(j);
    else
      vis[j]--;
  }
  return dp[i][vis.size()][prevG] = ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  long long i, j, n, m, k;
  cin >> n >> k;
  string s = to_string(n);
  map<long long, long long> vis;
  ans = doit(s, 0, 0, 0, k, vis);
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
}
long long mpow(long long base, long long exp) {
  base %= ((long long)1e9 + 7);
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % ((long long)1e9 + 7);
    base = ((long long)base * base) % ((long long)1e9 + 7);
    exp >>= 1;
  }
  return result;
}
void ipgraph(long long n, long long m) {
  long long i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(long long u, long long par) {
  for (long long v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
