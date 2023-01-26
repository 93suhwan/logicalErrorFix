#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265359;
long long inf = 1000000000000000007;
long long mod = 1000000007;
long long mod1 = 998244353;
const bool multi = 1;
vector<long long> G[200007];
long long p[200007];
void dfs(long long v, long long o) {
  p[v] = o;
  for (auto u : G[v]) {
    if (u == o) continue;
    dfs(u, v);
  }
}
long long ile[200007];
long long deg[200007];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  if (multi)
    cin >> tt;
  else
    tt = 1;
  while (tt--) {
    long long n, a, b;
    cin >> n;
    long long ans;
    for (long long i = 1; i < n; i++) {
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    dfs(1, -1);
    ans = 0;
    deque<long long> Q;
    for (long long i = 1; i <= n; i++) ile[i] = 0;
    for (long long i = 1; i <= n; i++) {
      deg[i] = (long long)(G[i]).size();
      if (i == 1) continue;
      if (deg[i] != 1)
        ile[p[i]]++;
      else {
        ans++;
        ile[i] = inf;
      }
    }
    for (long long i = 2; i <= n; i++)
      if (ile[i] == 0) Q.push_back(i);
    bool xd = 0;
    while (!Q.empty()) {
      long long v = Q[0];
      Q.pop_front();
      ans--;
      deg[p[v]]--;
      ile[p[v]]--;
      if (p[v] == 1) continue;
      if (deg[p[v]] == 1) {
        ans++;
        xd = 1;
        ile[p[p[v]]]--;
        if (p[p[v]] != 1 && ile[p[p[v]]] == 0) Q.push_back(p[p[v]]);
      } else {
        if (ile[p[v]] == 0) Q.push_back(p[v]);
      }
    }
    if (deg[1] == 0 && !xd) ans++;
    cout << ans << '\n';
    for (long long i = 1; i <= n; i++) G[i].clear();
  }
  return 0;
}
