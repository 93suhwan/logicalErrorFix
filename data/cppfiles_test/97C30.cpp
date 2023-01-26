#include <bits/stdc++.h>
using namespace std;
namespace Ruri {
const int infi = 1e9;
const long long infl = 4e18;
}  // namespace Ruri
using namespace Ruri;
namespace Gadgets {
inline long long ceil_div(long long a, long long b) { return (a + b - 1) / b; }
inline long long pos_mod(long long a, long long b) { return (a % b + b) % b; }
}  // namespace Gadgets
namespace Read {
inline int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long rl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline double rd() {
  double x;
  scanf("%lf", &x);
  return x;
}
}  // namespace Read
namespace DeBug {}
using namespace Gadgets;
using namespace Read;
using namespace DeBug;
const int MAX_N = 2e5 + 5;
int n;
vector<int> g[MAX_N];
vector<pair<int, int> > query[MAX_N];
int son[MAX_N];
int ans[MAX_N];
vector<int> dp[MAX_N];
void Dfs(int u, int fa) {
  dp[u].resize(son[u]);
  for (auto v : g[u])
    if (v != fa) {
      Dfs(v, u);
      if ((int)dp[u].size() < (int)dp[v].size())
        dp[u].resize((int)dp[v].size());
      for (int i = 0, bbb = (int)dp[v].size() - 1; i <= bbb; ++i)
        dp[u][i] += dp[v][i] - 1;
    }
  for (auto x : query[u])
    if (x.second < (int)dp[u].size()) ans[x.first] += dp[u][x.second];
  for (int i = 0, bbb = (int)dp[u].size() - 1; i <= bbb; ++i)
    dp[u][i] += son[u] - i;
  while (!dp[u].empty() && dp[u].back() <= 0) dp[u].pop_back();
}
int main() {
  n = ri();
  for (int i = 1, bbb = n - 1; i <= bbb; ++i) {
    int u = ri(), v = ri();
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1, bbb = n; i <= bbb; ++i) son[i] = (int)g[i].size() - (i != 1);
  int q = ri();
  for (int i = 1, bbb = q; i <= bbb; ++i) {
    int v = ri(), k = ri();
    query[v].push_back(pair<int, int>(i, k));
    ans[i] = son[v];
  }
  Dfs(1, 0);
  for (int i = 1, bbb = q; i <= bbb; ++i) printf("%d\n", ans[i]);
  return 0;
}
